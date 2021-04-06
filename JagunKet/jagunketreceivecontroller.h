///////////////////////////////////////////////////////////
//  JagunKETReceiveController.h
//  Implementation of the Class JagunKETReceiveController
//  Created on:      05-abr-2009 09:55:37
///////////////////////////////////////////////////////////

#ifndef JAGUNKETRECEIVECONTROLLER_H
#define JAGUNKETRECEIVECONTROLLER_H

#include <QUdpSocket>
#include <QByteArray>
#include <QHostAddress>
#include <QVector>
#include "jagunkettimer.h"
#include "jagunpackageinformation.h"

class JagunKETReceiveController : public QObject
{
    Q_OBJECT
public:
    /**
     * construtor
     */
    JagunKETReceiveController(QObject *parent,QUdpSocket *socket, QHostAddress address, quint16 port, quint32 idConnection, uint maxWaiting = 4000);
    /**
     * cancela recebimento do dado do servidor
     */
    void cancel();
    /**
     * recebe um datagrama do JagunKET
     */
    void receiveDatagram(QByteArray* datagram);
    /**
     * retorna se ainda esta recebendo um dado do servidor
     */
    bool stillReceiving();
    /**
     * estado do recebimento
     */
    enum EStatusReceiving
    {
        EStop    = 0,
        EReceiving = 1
    };

    enum EWJagunKETReceiveController
    {
        EWJKRCInvalidPackage     = 0 // dado recebido invalido
    };
signals:
    /**
     * nao conseguiu receber os dados por completo do servidor
     */
    void receiveFailure();
   /**
    * conclui recebimento de um dado do servidor e transmite um sinal com o dado
    */
    void receiveSuccess(QByteArray *data);
    /**
     * sinal para mensagens de warning
     */
    void warning(JagunKETReceiveController::EWJagunKETReceiveController warning);
protected slots:
    /**
     * tempo maximo sem chegar um novo dado, esgotado
     */
    void failure();
private:
    /**
     * Recupera a mensagem original e emite um sinal com a mensagem
     */
    void getNewMessage();
    QUdpSocket* udpSocket;
    QHostAddress address;
    quint16 port;
    quint32 idConnection;
    // buffer para receber os fragmentos da mensagem recebida
    QVector<QByteArray*> *bufferNewMessage;
    // tempo maximo para chegar um novo dado
    JagunKETTimer *timer;
    // status de recebimento
    EStatusReceiving statusReceiving;
};
#endif // JAGUNKETRECEIVECONTROLLER_H
