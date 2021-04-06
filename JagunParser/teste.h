#ifndef TESTE_H
#define TESTE_H

#include "jagunparserfromxml.h"
#include "jagunparsertoxml.h"

class Teste : public QObject
{
Q_OBJECT
public:
    Teste();
    void messageNewUser(const QString &login,const QString &password, const QString &email);
    void messageUserCreated(const QString &login, const QDateTime &date);
    void messageUserNotCreated(const QString &errorStr);
    void messageLoginUser(const QString &login,const QString &password);
    void messageLogOn(const QString &login, const QString &nickname, const QString &message, const QString &image, int status);
    void messageLoginUserError(const QString &errorStr);
    void messageAddContact(const QString &contact, const QString &message);
    void messageContactList(const QList<JagunMSNContact*>& list);
    void messageChangeStatus(const QString &nickname, const QString &message,
                             const QString &image, int status, const QList<QString> &sendToo);
protected slots:
    void newUser(QString login, QString password, QString email);
    void userCreated(QString login, QDateTime date);
    void userNotCreated(QString errorStr);
    void loginUser(QString login, QString password);
    void logOn(QString login, QString nickname, QString message, QString image, int status);
    void loginUserError(QString errorStr);
    void addContact(QString login, QString message);
    void contactList(QList<JagunMSNContact*> list);
    void changeStatus(QString nickname, QString message, QString image, int status, QStringList sendToo);
private:
    JagunParserFromXML parserFromXML;
    JagunParserToXML parserToXML;
};

#endif // TESTE_H
