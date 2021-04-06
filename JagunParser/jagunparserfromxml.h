#ifndef JAGUNPARSERFROMXML_H
#define JAGUNPARSERFROMXML_H

//#include <QtCore>
#include <QtXml>
#include <QString>
#include <QStringList>
#include <QDateTime>
#include <QList>

#include "jagunparsermessageinformation.h"
#include "jagunmsncontact.h"

/**
 * Classe responsavel pela decodificao da mensagem em xml
 */
class JagunParserFromXML : public QObject
{
    Q_OBJECT
public:
    inline JagunParserFromXML() {}
    /**
     * Faz o parser de qualquer mensagem em xml do JagunMSN
     */
    void parser(const QString &xml);
private:
    /**
     * Faz o parser da mensagem novo usuario do JagunMSN
     */
    void parserNewUser(const QString &xml);
    /**
     * Faz o parser da mensagem usuario cadastrado
     */
    void parserUserCreated(const QString &xml);
    /**
     * Faz o parser da mensagem erro
     */
    void parserErrorGeneral(const QString &xml);
    /**
     * Faz o parser da mensagem logar usuario
     */
    void parserLoginUser(const QString &xml);
    /**
     * Faz o parser da  mensagem usuario logado
     */
    void parserLogOn(const QString &xml);
    /**
     * Faz o parser da mensagem adicionar contato
     */
    void parserAddContact(const QString &xml);
    /**
     * Faz o parser da mensagem pedido de adicionar contato
     */
    void parserRequestAddContact(const QString &xml);
    /**
     * Faz o parser da mensagem reposta ao pedido de adicionar contato
     */
    void parserAddContactConfirmation(const QString &xml);
    /**
     * Faz o parser da menasgem contato adicionado com sucesso
     */
    void parserApprovedAddContact(const QString &xml);
    /**
     * Faz o parser da mensagem lista de contatos
     */
    void parserContactList(const QString &xml);
    /**
     * Faz o parser da mensagem remover contato
     */
    void parserRemoveContact(const QString &xml);
    /**
     * Faz o parser da mensagem bloquear ou desbloquear contato
     */
    void parserBlock(const QString &xml);
    /**
     * Faz o parser da mensagem mudanca de status do usuario
     */
    void parserChangeStatus(const QString &xml);
    /**
     * Faz o parser da mensagem requisitar status de um contato
     */
    void parserGetStatusContact(const QString &xml);
    /**
     * Faz o parser da mensagem mudanca de status do contato
     */
    void parserChangeStatusContact(const QString &xml);
    /**
     * Faz o parser da mensagem enviar mensagem
     */
    void parserSendMessage(const QString &xml);
    /**
     * Faz o parser da mensagem receber mensagem
     */
    void parserReceiveMessage(const QString &xml);
signals:
    /**
     * emite quando a mensagem decodificada for de cadastrar novo usuario
     */
    void newUser(QString login, QString password, QString email);
    /**
     * emite quando a mensagem decodificada for de usuario cadastrado
     */
    void userCreated(QString login, QDateTime date);
    /**
     * emite quando a mensagem decodificada foi de falha no cadastro do usuario
     */
    void userNotCreated(QString errorStr);
    /**
     * emite quanto a mensagem decodificada foi de logar usuario
     */
    void loginUser(QString login, QString password);
    /**
     * emite quando a mensagem decodificada foi de usuario logado
     */
    void logOn(QString login, QString nickname, QString message, QString image, int status);
    /**
     * emite quando a mensagem decodificada foi de erro ao logar usuario
     */
    void loginUserError(QString errorStr);
    /**
     * emite quando a mensagem decodificada foi de adicionar contato
     */
    void addContact(QString login, QString message);
    /**
     * emite quando a mensagem decodificada for de erro ao adicionar contato
     */
    void addContactError(QString errorStr);
    /**
     * emite quando a mensagem decodificada for de pedido de adicionar contato
     */
    void requestAddContact(QString from, QString message);
    /**
     * emite quando a mensagem decodificada for de resposta ao pedido de adicionar contato
     */
    void addContactConfirmation(QString to, bool confirmation);
    /**
     * emite quando a mensagem decodificada for de contato adicionado com sucesso
     */
    void approvedAddContact(QString login, QString nickname, QString message, QString image, int status);
    /**
     * emite quando a mensagem decodificada for de requisicao da lista de contatos
     */
    void requestContactList();
    /**
     * emite quando a mensagem decodificada for de lista de contatos
     */
    void contactList(QList<JagunMSNContact*> list);
    /**
     * emite quando a mensagem decodificada for de remover contato
     */
    void removeContact(QString login);
    /**
     * emite quando a mensagem decodificada for de bloquear ou desbloquear contato
     */
    void block(QString login, bool block);
    /**
     * emite quando a mensagem decodificada for de mudanca de status do usuario
     */
    void changeStatus(QString nickname, QString message, QString image, int status, QStringList sendToo);
    /**
     * emite quando a mensagem decodificada for de requisitar status de um contato
     */
    void getStatusContact(QString login);
    /**
     * emite quando a mensagem decodificada for de mudanca no status de um contato
     */
    void changeStatusContact(QString login, QString nickname, QString message, QString image, int status);
    /**
     * emite quando a mensagem decodificada for de keepalive
     */
    void keepAlive();
    /**
     * emite quando a mensagem decodificada for de enviar mensagem
     */
    void sendMessage(QStringList to, QString message, QDateTime dateSend);
    /**
     * emite quando a mensagem decodificada for de receber mensagem
     */
    void receiveMessage(QString from, QStringList to, QString message, QDateTime dateSend);
    /**
     * emite quando houver erro no parsing
     */
    void error(QString errorMsg, int errorLine, int errorColumn);
};

#endif // JAGUNPARSERFROMXML_H
