#ifndef JAGUNKET_H
#define JAGUNKET_H

/**
 * Tamanho maximo do buffer de mensagens
 */
#define MAX_BUFFER 10
/**
 * Numero maximo de tentativas de nova conexao
 */
#define MAX_TRY_ATTEMPTS_NEW_CONNECTION 10
/**
 * Intervalo para tentar uma nova conexao
 */
#define TIMER_INTERVAL_NEW_CONNECTION 2000
/**
 * Intervalo para tentar fechar a conexao
 */
#define TIMER_INTERVAL_CLOSE_CONNECTION 1000
/**
 * Numero maximo de tentativas para fechar a conexao
 */
#define MAX_TRY_ATTEMPTS_CLOSE_CONNECTION 20

#include <QByteArray>
#include <QUdpSocket>
#include <QHostAddress>
#include <QList>

#include "jagunketsendcontroller.h"
#include "jagunketreceivecontroller.h"
#include "jagunkettimer.h"

/**
 * classe responsavel pelo envio e recebimento de dados
 */
class JagunKET : public QObject
{
    Q_OBJECT
public:
    /**
     * Construtor
     */
    JagunKET(QObject *parent = 0);
    /**
     * Destrutor
     */
    ~JagunKET();
    /**
     * Envia um pedido de conexao a um host especificado pelo endereco e porta
     */
    virtual void connectToHost(const QHostAddress & address, quint16 port);
    /**
     * fecha a conexao depois que todos os dados forem enviados
     */
    virtual void close();
    /**
     * Envia um dado ao destinatario
     */
    virtual void send(QByteArray *data);

    /**
     * Retorna o estado atual do socket
     */
    virtual QAbstractSocket::SocketState getState() const;

    /**
     *
     */
    inline virtual quint32 getIdConnection() const {return idConnection;}

    /**
     * Tipos de erros
     */
    enum EErrorJagunKET
    {
        EEJKServerNotResponse = 0, // servidor nao responde
        EEJKPortNotAvailable  = 1, // nao existe porta disponivel para escuta
        EEJKSendData          = 2, // nao conseguiu enviar o dado
        EEJKReceiveData       = 3 //  nao conseguiu receber um dado
    };
    /**
     * Tipos de warnings
     */
    enum EWarningJagunKET
    {
        EWJKOtherActiveConnection = 0, // se o usuario tentar se conectar e ainda existe uma conexao ativa
        EWJKCloseInConnecting     = 1, // se o usuario tentar fechar a conexao no momento em que esta sendo estabelecida uma conexao
        EWJKNotConnected          = 2, // estado de nao conectado
        EWJKFullBufferMessages    = 3, // buffer de armazenar mensagens esta cheio
        EWJKConnectInClosing      = 4, // tenta conectar, mas esta fechando uma conexao
        EWJKCloseInClosing        = 5, // se o usuario tentar fechar a conexao no momento em que ja esta sendo fechada
        EWJKCloseInUnconnected    = 6, // se o usuario tentar fechar a conexao no momento nem esta conectado ao destinatario
    };
protected:
    /**
     * Processa o datagrama, redirecionando para os controles de envio ou recebimento
     */
    virtual void processDatagram(QByteArray *datagram);
    /**
     * tenta enviar uma mensagem do buffer
     */
    void trySend();
    // endereco do destinatario
    QHostAddress addressHost;
    // porta do destinatario
    quint16 portHost;
    // idenficador da conexao, se nao existe conexao entao o valor e' 0
    quint32 idConnection;
    // estado da conexao
    QAbstractSocket::SocketState state;
    // controlador dos pacotes enviados
    JagunKETSendController *sendController;
    // controlador dos pacotes recebidos
    JagunKETReceiveController *receiveController;
    // socket udp para escuta e envio de datagramas
    QUdpSocket *udpSocket;
    // buffer de mensagens que precisam ser enviadas
    QList<QByteArray*> bufferMessages;
signals:
    /**
     * sinal emitido quando o estado da conexao muda
     */
    void stateChanged(QAbstractSocket::SocketState socketState);
    /**
     * sinal emitido quando a conexao foi estabelecida
     */
    void connected();
    /**
     * sinal emitido quando o socket desconectou do destinatario
     */
    void disconnected();
    /**
     * sinal emitido quando houver algum erro em um processo
     */
    void error(JagunKET::EErrorJagunKET error);
    /**
     * sinal emitido quando ocorre algum warning
     */
    void warning(JagunKET::EWarningJagunKET warning);
    /**
     * Sinal emitido quando recebe um dado
     */
    void receive(QByteArray *data);
    /**
     * Sinal emitida quando uma mensagem foi recebida pelo destinatario
     */
    void sentData();
    /**
     * emitido quando o id dessa conexao estiver liberado
     */
    void idAvailable(quint32 id);
protected slots:
    /**
     * muda o estado da conexao
     */
     void setState(QAbstractSocket::SocketState newState);
    /**
     * executado quando um novo datagrama e' recebido
     */
    virtual void arrivedDatagram();
    /**
     * executado quando houver falha no recebimento de um dado do destinatario
     */
    virtual void receiveFailure();
    /**
     * executado quando o controlador de recebimento termina de receber um dado
     */
    //virtual void receiveSuccess(QByteArray *data);
    /**
     * Captura o sinal de falha ao enviar o dado do controlador de envio
     */
    virtual void sendFailure(QByteArray *data);
    /**
     * captura o sinal de dado enviado com sucesso do controlador de envio.
     * Depois chama trySend() para enviar o proximo dado
     */
    virtual void sendSuccess();
    /**
     * checa o estado quando acontece o maximo de timeouts para a tentativa de nova conexao, se o estado nao e' de conectado emite um erro
     */
    virtual void checkStateNewConnection();
    /**
     * envia um pacote de pedido de conexao
     */
    virtual void tryConnect();
    /**
     * tenta fechar a conexao
     */
    virtual void tryCloseConnection();
    /**
     * reinicia o estado das propriedades de controle
     */
    virtual void clean();
private:
    // temporizador de controle de tentativa de conexao
    JagunKETTimer *timerNewConnection;
    // temporizador de controle de fechamaneto da conexao
    JagunKETTimer *timerCloseConnection;
};

#endif // JAGUNKET_H
