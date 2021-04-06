#ifndef JAGUNMSNSERVER_H
#define JAGUNMSNSERVER_H

#include "jagunketserver.h"
#include "jagunmsnconnection.h"

class JagunMSNConnection;
class JagunMSNServer : public JagunKETServer
{
    Q_OBJECT
public:
    JagunMSNServer(quint16 portToListen,QObject *parent=0);
    /**
     * pega uma conexao dado seu id de conexao, retorna NULL caso nao exista
     */
    JagunMSNConnection* getConnection(quint32 id);
protected slots:
    /**
     * cria uma nova conexao para um determinado identificador de conexao, host e porta
     */
    void createNewConnection(quint32 idConnection,QHostAddress host,quint16 port);
};

#endif // JAGUNMSNSERVER_H
