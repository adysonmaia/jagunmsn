///////////////////////////////////////////////////////////
//  jagunketsendcontroller.cpp
//  Implementation of the Class JagunKETSendController
//  Created on:      05-abr-2009 00:37:22
///////////////////////////////////////////////////////////

#include "jagunketsendcontroller.h"


JagunKETSendController::JagunKETSendController(QObject *parent, QUdpSocket *socket, QHostAddress addressValue, quint16 portValue, quint32 connection,
                                               uint intervalValue, uint maxAttemptsValue) : QObject(parent)
{
    udpSocket = socket;
    address = addressValue;
    port = portValue;
    idConnection = connection;
    interval = intervalValue;
    maxAttempts = maxAttemptsValue;
    cancel();
}


void JagunKETSendController::cancel()
{
    listFragments.clear();
    statusSend = EStop;
    buffer = 0;
    numConfirmed = 0;
    ptWBegin = 0;
    ptWEnd = 0;

}

void JagunKETSendController::receiveConfirmationData(QByteArray* datagram)
{
    QDataStream in(datagram, QIODevice::ReadOnly);
    quint8 typeSegment;
    in >> typeSegment;
    if(typeSegment != JagunPackageInformation::ETPConfirmationData)
    {
        emit warning(EWJKSCDataIsNotConfirmationType);
        qDebug() << "JagunKETSendController:: tipo de pacote invalido";
        return;
    }
    quint32 connection;
    in >> connection;
    if(connection != idConnection)
    {
        emit warning(EWJKSCInvalidIdConnection);
        qDebug() << "JagunKETSendController:: Id de conexao invalido";
        return;
    }


    quint32 sequential;
    in >> sequential;
    delete datagram;
    //qDebug() << "JagunKETSendController:: recebeu confirmacao de um segmento com sequencial: " << sequential;
    // confirmacao que pode comecar a enviar os dados
    if(sequential == 0)
    {
        // se esse pacote ja foi confirmado, ignore ele
        if(listFragments[0]->confirmed())
            return;

        listFragments[0]->setConfirmed(true);
        ptWBegin = 1;
        ptWEnd = qMin((quint32) WINDOW_BUFFER_SIZE,(quint32) listFragments.size() - 2);
        sendBufferedData();
        return;
    }

    // confirmacao de fim de dado
    if(sequential == (quint32) listFragments.size() - 1)
    {
        listFragments[sequential]->setConfirmed(true);
        cancel();
        emit sendSuccess();
        qDebug() << "JagunKETSendController:: Mensagem enviado com sucesso ao destinatario";
        return;
    }

    // verificando se o numero de confirmacao esta no limite
    if(sequential <= (quint32) listFragments.size() - 2)
    {
        if(!listFragments[sequential]->confirmed())
        {
            numConfirmed+=(quint32) 1;
            listFragments[sequential]->setConfirmed(true);
        }

        // checa se todos os pacotes de dados foram enviados para enviar o pacote de fim de dado
        if(numConfirmed == (quint32) listFragments.size() - 2)
        {
            trySend((quint32) numConfirmed+1);
            listFragments[(int) numConfirmed+1]->startWaitConfirmation(interval,maxAttempts);
            return;
        }

        if(sequential == ptWBegin)
        {
            sendBufferedData();
            return;
        }
    }
    else
    {
        emit warning(EWJKSCInvalidSequential);
        qDebug() << "JagunKETSendController:: Sequencial recebido pelo destinatario invalido";
        return;
    }

}

void JagunKETSendController::send(QByteArray* data)
{
    if(statusSend == ESending)
    {
        emit warning(EWJKSCYetSending);
        qDebug() << "JagunKETSendController:: Impossivem enviar um novo dado. Motivo - Ja existe um dado sendo enviado a um destinatario";
        return;
    }
    qDebug() << "JagunKETSendController:: inicio de envio de mensagem pela conexao: " << idConnection;
    statusSend = ESending;
    buffer = new QByteArray(*data);
    buildFragments();
    if(listFragments.length() == 0)
    {
        QByteArray data(*buffer);
        sendFailure(&data);
        cancel();
        return;
    }

    // enviando o pacote inicio de dado
    trySend((quint32) 0);
    statusSend = ESending;
    listFragments[0]->startWaitConfirmation(interval,maxAttempts);

}

void JagunKETSendController::sendBufferedData()
{
    // deslocando a janela
    while(ptWEnd < (quint32) listFragments.size() - 2 && listFragments[ptWBegin]->confirmed())
    {
        ptWBegin+= (quint32) 1;
        ptWEnd+= (quint32) 1;
    }

    for(quint32 i = ptWBegin; i <= ptWEnd; i+= (quint32) 1)
    {
        if(!listFragments[(int) i]->isWaitingConfirmation() && !listFragments[(int) i]->confirmed())
        {
            trySend(i);
            listFragments[(int) i]->startWaitConfirmation(interval,maxAttempts);
        }
    }
}

void JagunKETSendController::buildFragments()
{
    if(buffer == 0)
        return;

    QByteArray bufferFragment;

    JagunKETFragmentSend *fragmentData = 0;
    quint32 iteratorFragment = 0;
    quint32 sequentialData   = 1;

    // se existem n fragmentos de dados entao
    // a lista possui n+2 elementos, o de indice 0 e' o pacote
    // do tipo inicio de dado e o de indice n+1 e' do tipo fim de dado
    do {
        bufferFragment = buffer->mid(iteratorFragment,FRAGMENT_SIZE_DATA);
        iteratorFragment+=FRAGMENT_SIZE_DATA;

        QByteArray *data = new QByteArray();
        QDataStream outData(data, QIODevice::WriteOnly);

        outData << (quint8) JagunPackageInformation::ETPData;
        outData << idConnection;
        outData << sequentialData;
        outData << (quint16) bufferFragment.size();
        outData << bufferFragment;

        fragmentData = new JagunKETFragmentSend(this);
        fragmentData->setData(*data,sequentialData);
        connect(fragmentData,SIGNAL(notConfirmed(quint32)),this,SLOT(trySend(quint32)));
        connect(fragmentData,SIGNAL(notConfirmedError(quint32)),this,SLOT(failure(quint32)));
        listFragments << fragmentData;

        sequentialData+=1;

    }while(iteratorFragment < (quint32) buffer->size());

    QByteArray *newData = new QByteArray();
    QByteArray *endData = new QByteArray();
    QDataStream outNewData(newData, QIODevice::WriteOnly);
    QDataStream outEndData(endData, QIODevice::WriteOnly);
    quint32 numData = (quint32) listFragments.size();
    JagunKETFragmentSend *fragmentNewData = 0;
    JagunKETFragmentSend *fragmentEndData = 0;

    outNewData << (quint8) JagunPackageInformation::ETPNewData;
    outNewData << idConnection;
    outNewData << numData;

    outEndData << (quint8) JagunPackageInformation::ETPEndData;
    outEndData << idConnection;

    fragmentNewData = new JagunKETFragmentSend(this);
    connect(fragmentNewData,SIGNAL(notConfirmed(quint32)),this,SLOT(trySend(quint32)));
    connect(fragmentNewData,SIGNAL(notConfirmedError(quint32)),this,SLOT(failure(quint32)));
    fragmentNewData->setData(*newData,0);

    numData+=(quint32)1;

    fragmentEndData = new JagunKETFragmentSend(this);
    connect(fragmentEndData,SIGNAL(notConfirmed(quint32)),this,SLOT(trySend(quint32)));
    connect(fragmentEndData,SIGNAL(notConfirmedError(quint32)),this,SLOT(failure(quint32)));
    fragmentEndData->setData(*endData,numData);

    listFragments.prepend(fragmentNewData);

    listFragments << fragmentEndData;

}

void JagunKETSendController::trySend(quint32 sequential)
{

    if(!listFragments[(int) sequential]->confirmed())
    {
        udpSocket->writeDatagram(listFragments[(int) sequential]->data(),address,port);
        //qDebug() << "JagunKETSendController:: Enviando Sequencial: " << sequential;
    }

}

bool JagunKETSendController::stillSending()
{
    return statusSend == ESending;
}

void JagunKETSendController::failure(quint32 sequential)
{
    qDebug() << "JagunKETSendController:: limite de reenvio excedido no sequencial: " << sequential;
    QByteArray data(*buffer);
    cancel();
    emit sendFailure(&data);
}
