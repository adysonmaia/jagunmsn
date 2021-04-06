#ifndef JAGUNCLIENTCONTROLLER_H
#define JAGUNCLIENTCONTROLLER_H

#include <QList>
#include "jagunket.h"
#include "jagunparserfromxml.h"
#include "jagunparsertoxml.h"
#include "jagunmsncontact.h"

#define TIME_KEEPALIVE 45000

/**
 * Classe responsavel pelo envio e recebimento de mensagens no JagunMSN cliente
 */
class JagunClientController : public QObject
{
    Q_OBJECT
public:
    JagunClientController(const QHostAddress & address, quint16 port,QObject *parent = 0);
public slots:
    /**
     * requisita cadastro de novo usuario no servidor
     */
    void newUser(QString login,QString password,QString email);
    /**
     * requsitar logar usuario no servidor
     */
    void loginUser(QString login, QString password);
    /**
     * adiconar contato a sua lista de contatos
     */
    void addContact(QString login, QString message);
    /**
     * avisa para o servidor que o status foi alterado, pede tambem para enviar o novo status para outros contatos
     */
    void changeStatus(QString nickname, QString message, QString image, int status, QStringList sendToo);
    /**
     * resposta ao pedido de adicionamento de contato
     */
    void addContactConfirmation(QString login, bool confirmation);
    /**
     * envia uma mensagem para uma lista de contatos
     */
    void sendMessage(QStringList to, QString message);
signals:
    /**
     * emite um erro quando o servidor não responde
     */
    void serverNotResponse();
    /**
     * emite quando um novo usuario cadastrado
     */
    void successNewUser();
    /**
     * emite quando erro na criação de um novo usuario
     */
    void failureNewUser(QString errorStr);

    /**
     * emite quando o usuario foi logado no servidor
     */
    void successloginUser(QString nickname, QString message, QString image, int status);
    /**
     * emite quando nao foi possivel logar o usuario
     */
    void failureLoginUser(QString errorStr);
    /**
     * emite quando recebe do servidor a lista de contatos
     */
    void contactList(QList<JagunMSNContact*> list);
    /**
     * emite quando algum contato pede para ser adicionado
     */
    void requestAddContact(QString login, QString message);
    /**
     * emite quando um novo contato foi adicinado a lista de contatos
     */
    void newContact(JagunMSNContact *newContact);
    /**
     * emite quando um contato muda de status
     */
    void contactChangeStatus(JagunMSNContact *newContact);
    /**
     * emite quando recebe uma mensagem de from, e que ele tambem mandou para os to
     */
    void receiveMessage(QString from, QStringList to, QString message);
    /**
     * emite quando o usuario se desconecta
     */
    void logoff();
protected slots:
    /**
     * conexao estabelecida para fazer a requisicao de novo usuario
     */
    void connectedNewUser();
    /**
     * conexao fechada do requisito de cadastro de novo usuario
     */
    void disconnectedNewUser();
    /**
     * erro ao tentar comunicar-se com o servidor
     */
    void errorServerNewUser(JagunKET::EErrorJagunKET error);

    /**
     * servidor responde que o usuario foi cadastrado
     */
    void userCreated(QString login, QDateTime date);

    /**
     * servidor responde que o usuario nao foi cadastrado
     */
    void userNotCreated(QString errorStr);

    void keepAlive();
    /**
     * conexao estabelecida com o servidor
     */
    void connectedServer();
    /**
     * conexao fechada com o servidor
     */
    void disconnectedServer();
    /**
     * recebeu dados do servidor
     */
    void receiveServer(QByteArray *data);
    /**
     * erro ao tentar comunicar-se com o servidor
     */
    void errorServer(JagunKET::EErrorJagunKET error);

    /**
     * usuario logado
     */
    void logOn(QString login, QString nickname, QString message, QString image, int status);
    /**
     * nao conseguiu logar usuario
     */
    void loginUserError(QString errorStr);
    /**
     * contato adicionado
     */
    void approvedAddContact(QString login, QString nickname, QString message, QString image, int status);
    /**
     * mudanca de status de um contato
     */
    void changeStatusContact(QString login, QString nickname, QString message, QString image, int status);

private:
    //sockets
    JagunKET *socket;
    JagunKET *socketNewUser;

    // endereco do destinatario
    QHostAddress addressHost;
    // porta do destinatario
    quint16 portHost;

    QTimer timerKeepAlive;

    // parsers
    JagunParserFromXML parserFromXML;
    JagunParserToXML parserToXML;

    // dados para criar uma nova conta
    QString newUserLogin;
    QString newUserPassword;
    QString newUserEmail;

    // dados do usuario conectado
    QString userLogin;
    QString userPassword;

    bool logged;
};

#endif // JAGUNCLIENTCONTROLLER_H
