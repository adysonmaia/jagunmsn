#ifndef JAGUNPARSERTOXML_H
#define JAGUNPARSERTOXML_H

//#include <QtCore>
#include <QtXml>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QDateTime>
#include <QList>

#include "jagunparsermessageinformation.h"
#include "jagunmsncontact.h"

/**
 * Classe responsavel pela codificao de uma mensagem do JagunMSN em xml
 */
class JagunParserToXML : public QObject
{
public:
    inline JagunParserToXML() {}
    /**
     * codifica a mensagem do tipo cadastrar novo usuario em xml
     */
    QString newUser(const QString &login,const QString &password, const QString &email);
    /**
     * codifica mensagem do tipo usuario cadastrado
     */
    QString userCreated(const QString &login, const QDateTime &date);
    /**
     * codifica mensagem do tipo falha no cadastro do usuario
     */
    QString userNotCreated(const QString &errorStr);
    /**
     * codifica mensagem do tipo logar usuario
     */
    QString loginUser(const QString &login, const QString &password);
    /**
     * codifica mensagem do tipo usuario logado
     */
    QString logOn(const QString &login, const QString &nickname, const QString &message, const QString &image, int status);
    /**
     * codifica mensagem do tipo erro ao logar usuario
     */
    QString loginUserError(const QString &errorStr);
    /**
     * codifica mensagem do tipo adicionar contato
     */
    QString addContact(const QString &login, const QString &message);
    /**
     * codifica mensagem do tipo erro ao adicionar contato
     */
    QString addContactError(const QString &errorStr);
    /**
     * codifica mensagem do tipo pedido para adicionar contato
     */
    QString requestAddContact(const QString &from, const QString &message);
    /**
     * codifica mensagem do tipo resposta ao pedido de adicionar contato
     */
    QString addContactConfirmation(const QString &to, bool confirmation);
    /**
     * codifica mensagem do tipo contato adicionado com sucesso
     */
    QString approvedAddContact(const QString &login, const QString &nickname, const QString &message, const QString &image, int status);
    /**
     * codifica mensagem do tipo requisita lista de contatos
     */
    QString requestContactList();
    /**
     * codifica mensagem do tipo lista de contatos
     */
    QString contactList(const QList<JagunMSNContact*> &list);
    /**
     * codifica mensagem do tipo remover contato
     */
    QString removeContact(const QString& login);
    /**
     * codifica mensagem do tipo bloquear ou desbloquear contato
     */
    QString block(const QString& login, bool block);
    /**
     * codifica mensagem do tipo mudanca de status do usuario
     */
    QString changeStatus(const QString &nickname, const QString &message,
                         const QString &image, int status, const QStringList &sendToo);
    /**
     * codifica mensagem do tipo requisicao de status de um contato
     */
    QString getStatusContact(const QString &login);
    /**
     * codifica mensagem do tipo mudanca no status de um contato
     */
    QString changeStatusContact(const QString &login, const QString &nickname, const QString &message, const QString &image, int status);
    /**
     * codifica mensagem do tipo keep alive
     */
    QString keepAlive();
    /**
     * codifica mensagem do tipo enviar mensagem
     */
    QString sendMessage(const QStringList& to, const QString& message, const QDateTime &dateSend);
    /**
     * codifica mensagem do tipo receber mensagem
     */
    QString receiveMessage(const QString &from, const QStringList& to, const QString& message, const QDateTime &dateSend);
protected:
    /**
     * codifica mensagem de erro geral
     */
    QString messageErrorGeneral(JagunParserMessageInformation::EErrorCode code, const QString &errorStr);
};

#endif // JAGUNPARSERTOXML_H
