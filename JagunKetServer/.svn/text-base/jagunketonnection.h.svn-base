///////////////////////////////////////////////////////////
//  JagunKETConnection.h
//  Implementation of the Class JagunKETConnection
//  Created on:      05-abr-2009 09:58:09
///////////////////////////////////////////////////////////

#ifndef JAGUNKETCONNECTION_H
#define JAGUNKETCONNECTION_H

#include "jagunket.h"
#include "jagunketserver.h"
#include <QObject>
class JagunKETConnection : public JagunKET
{
    Q_OBJECT
public:
    /**
     * construtor, recebe o servidor que controle essa conexao como argumento
     */
    JagunKETConnection(JagunKETServer *parentServer,QUdpSocket *udpSocket);
    /**
     * atribui as informacoes necessarias para gerenciar uma conexao
     */
    void setConnection(quint32 idConnection, const QHostAddress& address, quint16 port);
    /**
     * estabelece o tempo de vida da conexao
     */
    void setLifeTimer(quint32 time);
    /**
     * JagunKET overload
     */
    void receiveDatagram(QByteArray *datagram);
private:
    // POG
    void arrivedDatagram(){}
    // POG
    void connectToHost(const QHostAddress & address, quint16 port){}
    /**
     * JagunKET overload
     */
    void clean();
private slots:
    void kill();
signals:
    /**
     * emitido quando a conexao for destruida
     */
    void killed();
};
#endif // JAGUNKETCONNECTION_H
