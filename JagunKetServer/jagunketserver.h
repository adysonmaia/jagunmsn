#ifndef JAGUNKETSERVER_H
#define JAGUNKETSERVER_H

#include <QUdpSocket>
#include <QList>
#include <QByteArray>
#include <QHostAddress>


#define LIMIT_CONNECTIONS 200

class JagunKETServer : public QObject
{
    Q_OBJECT
public:
    /**
     * Construtor
     */
    JagunKETServer(quint16 portToListen,QObject *parent=0);
    /**
     * Enum de tipos de Warning
     */
    enum EWarningJagunKETServer
    {
        EWJKSFullConnectionBuffer = 0 // numero maximo de conexoes atingido
    };
    /**
     * Enum de tipos de erro
     */
    enum EErrorJagunKETServer
    {
        EEJKSPortNotAvailable = 0 // nao existe nenhuma porta disponivel para o servidor escutar
    };
protected:
    QUdpSocket *udpSocket;
private:
    // lista de ids disponiveis para conexao
    QList<quint32> qlAvalibleId;

    /**
     * cria uma lista identificadores disponiveis para novas conexoes
     */
    void buildAvailableIds();

    /**
     * retorna um novo identificador de conexao se disponivel, caso contrario 0
     */
    quint32 getAvailableId();

    /**
     * Processa um novo datagrama
     */
    void processDatagram(QByteArray * datagram,const QHostAddress & address, quint16 port);
    /**
     * processa o pedido de uma nova conexao
     */
    void processNewConnection(const QHostAddress & address, quint16 port);
    /**
     * processa pacote do tipo dado
     */
    void processData(QByteArray * datagram,const QHostAddress & address, quint16 port);
private slots:
    /**
     * Processa os pacotes recebidos
     */
    void read();

    /**
     * recupera um id liberado
     */
    void getDisposableId(quint32 id);
protected slots:
    /**
     * cria uma nova conexao para um determinado identificador de conexao, host e porta
     */
    virtual void createNewConnection(quint32 idConnection,QHostAddress host,quint16 port);
signals:
    /**
     * sinal emitido quando e' necessario criar uma nova conexao
     */
    void newConnectionAvailable(quint32 idConnection,QHostAddress host,quint16 port);
    /**
     * sinal emitido quando ocorre algum warning
     */
    void warning(JagunKETServer::EWarningJagunKETServer warning);
    /**
     * sinal emitido quando ocorre algum erro
     */
    void error(JagunKETServer::EErrorJagunKETServer error);

};

#endif // JAGUNKETSERVER_H
