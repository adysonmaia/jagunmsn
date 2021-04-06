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
     * destrutor, emite sinal de id da conexao disponivel
     */
    inline ~JagunKETConnection() {emit idAvailable(idConnection);}
    /**
     * atribui as informacoes necessarias para gerenciar uma conexao
     */
    void setConnection(quint32 idConnection, const QHostAddress& address, quint16 port);
    
    /**
     * JagunKET overload
     */
    void receiveDatagram(QByteArray *datagram, const QHostAddress & address, quint16 port);
private:
    // POG
    void arrivedDatagram(){}
    // POG
    void connectToHost(const QHostAddress & address, quint16 port){}
    /**
     * JagunKET overload
     */
    void clean();
};
#endif // JAGUNKETCONNECTION_H
