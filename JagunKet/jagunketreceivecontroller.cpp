///////////////////////////////////////////////////////////
//  JagunKETReceiveController.cpp
//  Implementation of the Class JagunKETReceiveController
//  Created on:      05-abr-2009 09:55:37
///////////////////////////////////////////////////////////

#include "jagunketreceivecontroller.h"


JagunKETReceiveController::JagunKETReceiveController(QObject *parent,QUdpSocket *socket, QHostAddress addressValue,
                                                     quint16 portValue, quint32 connection,
                                                     uint maxWaiting) : QObject(parent)
{
    udpSocket = socket;
    address = addressValue;
    port = portValue;
    idConnection = connection;
    bufferNewMessage = 0;
    timer = new JagunKETTimer(this,1);
    timer->setIntervalCounting(maxWaiting);
    cancel();
    connect(timer, SIGNAL(finished()), this, SLOT(failure()));
}

void JagunKETReceiveController::cancel()
{
    timer->stopCounting();
    delete bufferNewMessage;
    bufferNewMessage = 0;
    statusReceiving = EStop;
}

void JagunKETReceiveController::receiveDatagram(QByteArray* datagram)
{
    QDataStream in(datagram, QIODevice::ReadOnly);

    QByteArray confirmation;
    QDataStream out(&confirmation, QIODevice::WriteOnly);

    quint8 typeSegment;
    quint32 connection;
    in >> typeSegment;
    in >> connection;
    if (connection != idConnection)
    {
        delete datagram;
        return;
    }
    switch(typeSegment)
    {
        case(JagunPackageInformation::ETPNewData):
            timer->stopCounting();
            if (statusReceiving == EStop)
            {
                qDebug() << "JagunKETReceiveController :: iniciar recebimento de um novo dado";
                statusReceiving = EReceiving;
                quint32 sizeBuffer;
                in >> sizeBuffer;
                bufferNewMessage = new QVector<QByteArray*>((int) sizeBuffer,0);
            }

            out << (quint8) JagunPackageInformation::ETPConfirmationData;
            out << idConnection;
            out << (quint32) 0;
            udpSocket->writeDatagram(confirmation,address,port);
            timer->startCounting();
            break;
        case(JagunPackageInformation::ETPData):
            if (statusReceiving != EReceiving)
            {
                qDebug() << "JagunKETReceiveController:: Dado recebido mas ignorado pois nao foi enviado um pacote de novo dado";
                emit warning(EWJKRCInvalidPackage);
                break;
            }
            timer->stopCounting();
            //qDebug() << "JagunKETReceiveController:: recebeu parte de um dado";
            quint32 sequential;
            in >> sequential ;

            if(bufferNewMessage->value((int) sequential - 1) == 0)
            {
                quint16 size;
                in >> size;
                char *rawData = new char[(int) size];
                in >> rawData;
                bufferNewMessage->data()[(int) sequential - 1] = new QByteArray(rawData,(int) size);
                delete[] rawData;
            }

            out << (quint8) JagunPackageInformation::ETPConfirmationData;
            out << idConnection;
            out << sequential;
            udpSocket->writeDatagram(confirmation,address,port);
            timer->startCounting();
            break;
        case(JagunPackageInformation::ETPEndData):
            if (statusReceiving != EReceiving)
            {
                //qDebug() << "JagunKETReceiveController:: Fim de dado recebido reenviando confirmacao se possivel";
            }
            qDebug() << "JagunKETReceiveController:: fim de recebimento de um dado";
            timer->stopCounting();
            if(bufferNewMessage != 0)
            {
                out << (quint8) JagunPackageInformation::ETPConfirmationData;
                out << idConnection;
                out << (quint32) bufferNewMessage->size() + 1;
                udpSocket->writeDatagram(confirmation,address,port);
                getNewMessage();
                cancel();
            }
            break;
        default:
            emit warning(EWJKRCInvalidPackage);
            qDebug() << "JagunKETReceiveController:: Tipo de pacote invalido";
            break;
    }
    delete datagram;
}

void JagunKETReceiveController::getNewMessage()
{

    if(bufferNewMessage == 0) return;
    QByteArray result;
    for(int i = 0; i < bufferNewMessage->size(); i++)
    {
        result.append(*(bufferNewMessage->data()[i]));
    }

    qDebug() << "JagunKETReceiveController:: Mensagem Recebida:";
    qDebug() << result;
    emit receiveSuccess(&result);

}

bool JagunKETReceiveController::stillReceiving()
{
    return statusReceiving == EReceiving;
}

void JagunKETReceiveController::failure()
{
    qDebug() << "JagunKETReceiveController:: tempo maximo de espera para um novo dado esgotado";
    cancel();
    emit receiveFailure();
}
