#include "jagunketserver.h"
#include "jagunpackageinformation.h"
#include "jagunketconnection.h"

#include <QList>
#include <QDataStream>
#include <QByteArray>

JagunKETServer::JagunKETServer(quint16 portToListen,QObject *parent) : QObject(parent)
{
    udpSocket = new QUdpSocket(this);

    if(!udpSocket->bind(portToListen))
    {
        qDebug() << "JagunKETServer:: Impossivel escutar a porta: " << portToListen;
        emit error(EEJKSPortNotAvailable);
    }

    buildAvailableIds();

    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(read()));
    connect(this,SIGNAL(newConnectionAvailable(quint32,QHostAddress,quint16)),SLOT(createNewConnection(quint32,QHostAddress,quint16)));
}

void JagunKETServer::read()
{
    //qDebug() << "JagunKETServer:: novo pacote recebido";

    QHostAddress addressHost;
    quint16 portHost;
    QByteArray *datagram = new QByteArray();

    datagram->resize(udpSocket->pendingDatagramSize());
    udpSocket->readDatagram(datagram->data(), datagram->size(),&addressHost, &portHost);

    processDatagram(datagram,addressHost,portHost);

}

void JagunKETServer::processDatagram(QByteArray * datagram,const QHostAddress & address, quint16 port)
{
    QDataStream in(datagram, QIODevice::ReadOnly);
    quint8 typePackage;
    in >> typePackage;

    //qDebug() << "JagunKETServer:: Pacote recebido: " << JagunPackageInformation::getLiteralTypePackage((int) typePackage);

    switch(typePackage)
    {
        case(JagunPackageInformation::ETPNewConnection):
            processNewConnection(address,port);
            break;
        case(JagunPackageInformation::ETPData):
            processData(datagram,address,port);
            break;
        case(JagunPackageInformation::ETPEndData):
            processData(datagram,address,port);
            break;
        case(JagunPackageInformation::ETPNewData):
            processData(datagram,address,port);
            break;
        default:
        case(JagunPackageInformation::ETPConnectionClosed):
            processData(datagram,address,port);
            break;
    }
}

void JagunKETServer::processData(QByteArray * datagram,const QHostAddress & address, quint16 port)
{
    QDataStream in(datagram, QIODevice::ReadOnly);
    quint8 typePackage;
    quint32 idConnection;
    in >> typePackage;
    in >> idConnection;

    if(idConnection <=0)
    {
        // TODO - informar problema
        qDebug() << "JagunKETServer:: Pacote recebido mas id de conexao invalida: " << idConnection;
        return;
    }

    //qDebug() << "JagunKETServer:: Pacote encaminhado para a conexao: " << idConnection;

    JagunKETConnection *connection = findChild<JagunKETConnection*>(QString("%1").arg(idConnection));
    if(!connection)
    {
        // TODO - informar problema
        qDebug() << "JagunKETServer:: Nao existe gerenciador para o ID: " << idConnection;
        return;
    }
    connection->receiveDatagram(datagram,address,port);

}

void JagunKETServer::processNewConnection(const QHostAddress & address, quint16 port)
{
    quint32 idNewConnection = getAvailableId();
    if(idNewConnection == 0)
    {
        qDebug() << "JagunKETServer:: Buffer Cheio - Nao e' possivel criar uma nova conexao";
        emit warning(EWJKSFullConnectionBuffer);
        return;
    }

    // pacote do tipo Conexao Estabelecida
    QByteArray datagram;
    QDataStream out(&datagram,QIODevice::WriteOnly);
    out << (quint8) JagunPackageInformation::ETPConnectionEstablished << idNewConnection;

    //qDebug() << "JagunKETServer:: Conexao estabelecida - enviando resposta para: " << address << ":" << port;
    udpSocket->writeDatagram(datagram,address,port);

    emit newConnectionAvailable(idNewConnection,address,port);
}

void JagunKETServer::buildAvailableIds()
{
    for(quint32 i = 1; i <= LIMIT_CONNECTIONS; i++)
    {
        qlAvalibleId << i;
    }
}

quint32 JagunKETServer::getAvailableId()
{

    if(qlAvalibleId.length() == 0)
    {
        return 0;
    }
    return qlAvalibleId.takeFirst();
}

 void JagunKETServer::createNewConnection(quint32 idConnection,QHostAddress host,quint16 port)
 {
     JagunKETConnection *newConnection = new JagunKETConnection(this,udpSocket);
     newConnection->setConnection(idConnection,host,port);
     connect(newConnection,SIGNAL(idAvailable(quint32)),this,SLOT(getDisposableId(quint32)));

 }

 void JagunKETServer::getDisposableId(quint32 id)
 {
     if(!qlAvalibleId.contains(id))
     {
         qlAvalibleId.append(id);
     }
     return;
 }
