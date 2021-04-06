///////////////////////////////////////////////////////////
//  JagunKETConnection.cpp
//  Implementation of the Class JagunKETConnection
//  Created on:      05-abr-2009 09:58:10
///////////////////////////////////////////////////////////

#include "jagunketconnection.h"


JagunKETConnection::JagunKETConnection(JagunKETServer *parentServer, QUdpSocket *udpSocket) : JagunKET(parentServer)
{
    this->udpSocket = udpSocket;
}

void JagunKETConnection::setConnection(quint32 idConnection, const QHostAddress& address, quint16 port)
{
    state               = QAbstractSocket::ConnectedState;
    this->idConnection  = idConnection;
    addressHost         = address;
    portHost            = port;

    // o nome do objeto agora e' o id da conexao. desta forma o objeto pode ser recuperado pelo parent
    setObjectName(QString("%1").arg(idConnection));

    //cria controladores
    sendController    = new JagunKETSendController(this,udpSocket, addressHost, portHost, idConnection);
    receiveController = new JagunKETReceiveController(this,udpSocket, addressHost, portHost, idConnection);

    connect(sendController,SIGNAL(sendSuccess()),this,SLOT(sendSuccess()));
    connect(sendController,SIGNAL(sendSuccess()),this,SIGNAL(sentData()));
    connect(sendController,SIGNAL(sendFailure(QByteArray*)),this,SLOT(sendFailure(QByteArray*)));
    connect(receiveController,SIGNAL(receiveSuccess(QByteArray*)),this,SIGNAL(receive(QByteArray*)));
    connect(receiveController,SIGNAL(receiveFailure()),this,SLOT(receiveFailure()));

    emit stateChanged(QAbstractSocket::ConnectedState);
}

void JagunKETConnection::receiveDatagram(QByteArray *datagram,const QHostAddress & address, quint16 port)
{

    if(state == QAbstractSocket::UnconnectedState)
    {
        qDebug() << "JagunKETConnection:: Pacote recebido mas ignorado. Motivo: Nao foi estabelecido uma conexao oficial como o destinatario";
        return;
    }


    if(address != addressHost || port != portHost)
    {
        qDebug() << "JagunKETConnection:: Pacote recebido mas ignorado. Motivo: remetente desconhecido";
        delete datagram;
        return;
    }

    processDatagram(datagram);
}

void JagunKETConnection::clean()
{
    udpSocket                     = 0;
    emit stateChanged(QAbstractSocket::UnconnectedState);
    if(receiveController)
    {
        delete receiveController;
    }
    receiveController             = 0;
    if(sendController)
    {
        delete sendController;
    }
    sendController                = 0;
    portHost                      = 0;
    idConnection                  = 0;
}
