#ifndef JAGUNMSNCONNECTION_H
#define JAGUNMSNCONNECTION_H

#include <QTextCodec>
#include <QList>
#include "jagunmsnserver.h"
#include "jagunketconnection.h"
#include "jagunparserfromxml.h"
#include "jagunparsertoxml.h"
#include "jagundb.h"

#define LIFE_TIME 1200000

/**
 * classe responsavel pela conexao entre um cliente
 */
class JagunMSNConnection : public JagunKETConnection
{
    Q_OBJECT
public:
    JagunMSNConnection(JagunKETServer *parentServer,QUdpSocket *udpSocket, int lifeTime = LIFE_TIME);
    /**
     * estabelece o tempo de vida da conexao
     */
    void setLifeTimer(int time);
protected slots:
    void errorConnection(JagunKET::EErrorJagunKET error);
    void disconnectedConnection();
    void readClient(QByteArray *data);

    void timeout();

    /**
     * cliente requisita um cadastro de usuario
     */
    void newUser(QString login, QString password, QString email);
    /**
     * cliente requisita logar
     */
    void loginUser(QString login, QString password);
    /**
     * cliente requisita lista de contatos
     */
    void requestContactList();
    /**
     * cliente requisita adicionar contato a sua lista de contatos
     */
    void addContact(QString login, QString message);
    /**
     * cliente envia confirmacao de pedido de adicionamento
     */
    void addContactConfirmation(QString to, bool confirmation);
    /**
     * cliente alterou seu status
     */
    void changeStatus(QString nickname, QString message, QString image, int status, QStringList sendToo);
    /**
     * cliente enviou uma mensagem
     */
    void sendMessage(QStringList to, QString message, QDateTime dateSend);
protected:
    /**
     * envia todos os pedidos de adicionar contatos nao confirmados para o usuario
     */
    void sendAllRequestAddContact();

    /**
     * retorna outra conexao, dado o seu id de conexao
     */
    JagunMSNConnection* getOtherConnection(quint32 id);
private:
    JagunParserFromXML parserFromXML;
    JagunParserToXML parserToXML;
    JagunDb db;
    QTimer lifeTimer;
    int time;

    // esta logado ou nao
    bool logged;
    QString userLogin;
    int userStatus;
};

#endif // JAGUNMSNCONNECTION_H
