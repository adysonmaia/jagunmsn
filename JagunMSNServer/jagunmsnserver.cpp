#include "jagunmsnserver.h"

JagunMSNServer::JagunMSNServer(quint16 portToListen,QObject *parent)
               : JagunKETServer(portToListen,parent)
{
    qDebug() << "JagunMSNServer :: servidor rodando";
}

void JagunMSNServer::createNewConnection(quint32 idConnection,QHostAddress host,quint16 port)
{
    qDebug() << "JagunMSNServer :: nova conexao";
    JagunMSNConnection *newConnection = new JagunMSNConnection(this,udpSocket);
    newConnection->setConnection(idConnection,host,port);
    connect(newConnection,SIGNAL(idAvailable(quint32)),this,SLOT(getDisposableId(quint32)));
}

JagunMSNConnection* JagunMSNServer::getConnection(quint32 id)
{
    JagunMSNConnection *connection = findChild<JagunMSNConnection*>(QString("%1").arg(id));
    return connection;
}
