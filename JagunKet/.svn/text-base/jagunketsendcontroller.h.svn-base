///////////////////////////////////////////////////////////
//  jagunketsendcontroller.h
//  Implementation of the Class JagunKETSendController
//  Created on:      05-abr-2009 00:37:21
///////////////////////////////////////////////////////////

#ifndef JAGUNKETSENDCONTROLLER_H
#define JAGUNKETSENDCONTROLLER_H

/**
 * Tamanho maximo de um dado no pacote, default 488
 */
#define FRAGMENT_SIZE_DATA 500

/**
 * Tamanho da janela de controle de envio
 */
#define WINDOW_BUFFER_SIZE 10

#include <QUdpSocket>
#include <QByteArray>
#include <QHostAddress>
#include "jagunkettimer.h"
#include "jagunpackageinformation.h"
#include "jagunketfragmentsend.h"

/**
 * Controla o buffer de envio do socket
 */
class JagunKETSendController : public QObject
{
    Q_OBJECT
public:
    /**
    * contrutor
    */
    JagunKETSendController(QObject *parent, QUdpSocket *socket, QHostAddress address, quint16 port, quint32 idConnection,
                           uint interval = 2000, uint maxAttemps = 10);
    /**
     * cancela envio do dado ao servidor
     */
    void cancel();
    /**
     * recebe um datagrama de confirmacao do JagunKET, ou outra classe
     */
    void receiveConfirmationData(QByteArray* datagram);
    /**
     * envia um dado ao servidor, se nao esta enviando outro
     */
    void send(QByteArray* data);
    /**
     * retorna se ainda esta enviando um dado
     */
    bool stillSending();
    /**
     * estado do envio
     */
    enum EStatusSend
    {
        EStop    = 0,
        ESending = 1
    };
    /**
     * Tipos de warning
     */
    enum EWarningJagunKETSendController
    {
       EWJKSCDataIsNotConfirmationType = 0, // pacote recebido mas nao e' do tipo confirmacao de dado
       EWJKSCInvalidIdConnection       = 1, // id de conexao invalido
       EWJKSCInvalidSequential         = 2, // sequencial enviado pelo destinatario invalido
       EWJKSCYetSending                = 3, // ainda esta enviando um dado e nao e' possivel enviar outro

    };
signals:
    /**
     * falha em enviar o dado
     */
    void sendFailure(QByteArray *data);
    /**
     * dado enviado para o servidor com sucesso
     */
    void sendSuccess();
    /**
     * sinal com mensagem de warning
     */
    void warning(JagunKETSendController::EWarningJagunKETSendController warning);
protected slots:
    /**
     * limite de reenvio excedido
     */
    void failure(quint32 sequential);
    /**
     * envia um segmento identificado pelo sequencial
     */
    void trySend(quint32 sequential);
private:
    /**
     * constroi a lista de fragmentos do buffer
     */
    void buildFragments();
    /**
     * envia os dados dentro do buffer (janela)
     */
    void sendBufferedData();
    // socket para envio ao destinatario
    QUdpSocket* udpSocket;
    // endereco do destinatario
    QHostAddress address;
    // porta do destinatario
    quint16 port;
    // identificador da conexao com o destinatario
    quint32 idConnection;
    // dado que sera enviado
    QByteArray* buffer;
    // status da classe
    EStatusSend statusSend;
    // intervalo do timeouts
    uint interval;
    // numero maximo de tentativas por para tentar enviar um pacote
    uint maxAttempts;
    // lista de fragmentos de dados
    QList<JagunKETFragmentSend*> listFragments;
    // indica quantos pacotes ja foram confirmados
    quint32 numConfirmed;
    // ponteiro inicial da janela do buffer de envio
    quint32 ptWBegin;
    // ponteiro final da janela do buffer de envio
    quint32 ptWEnd;
};
#endif // JAGUNKETSENDCONTROLLER_H
