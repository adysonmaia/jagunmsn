#include "teste.h"

Teste::Teste()
{
    connect(&parserFromXML, SIGNAL(newUser(QString,QString,QString) ), this, SLOT (newUser(QString,QString,QString) ) );
    connect(&parserFromXML, SIGNAL(userCreated(QString,QDateTime) ), this, SLOT(userCreated(QString,QDateTime) ) );
    connect(&parserFromXML, SIGNAL(userNotCreated(QString) ), this, SLOT(userNotCreated(QString) ) );
    connect(&parserFromXML, SIGNAL(loginUser(QString,QString) ), this, SLOT (loginUser(QString,QString) ) );
    connect(&parserFromXML, SIGNAL(logOn(QString, QString, QString, QString, int) ), this, SLOT(logOn(QString, QString, QString, QString, int) )  );
    connect(&parserFromXML, SIGNAL(loginUserError(QString) ), this, SLOT(loginUserError(QString) ) );
    connect(&parserFromXML, SIGNAL(addContact(QString, QString) ), this, SLOT(addContact(QString, QString) ) );
    connect(&parserFromXML, SIGNAL(contactList(QList<JagunMSNContact*>) ), this, SLOT(contactList(QList<JagunMSNContact*>) ) );
    connect(&parserFromXML, SIGNAL(changeStatus(QString, QString, QString, int, QStringList) ), this, SLOT(changeStatus(QString, QString, QString, int, QStringList) ) );
}

void Teste::messageNewUser(const QString &login,const QString &password, const QString &email)
{
    QString xml = parserToXML.newUser(login,password,email);
    qDebug() << xml;
    parserFromXML.parser(xml);
}

void Teste::messageUserCreated(const QString &login, const QDateTime &date)
{
    QString xml = parserToXML.userCreated(login,date);
    qDebug() << xml;
    parserFromXML.parser(xml);
}

void Teste::messageUserNotCreated(const QString &errorMsg)
{
    QString xml = parserToXML.userNotCreated(errorMsg);
    qDebug() << xml;
    parserFromXML.parser(xml);
}

void Teste::messageLoginUser(const QString &login,const QString &password)
{
    QString xml = parserToXML.loginUser(login,password);
    qDebug() << xml;
    parserFromXML.parser(xml);
}

void Teste::messageLogOn(const QString &login, const QString &nickname, const QString &message, const QString &image, int status)
{
    QString xml = parserToXML.logOn(login, nickname, message, image, status);
    qDebug() << xml;
    parserFromXML.parser(xml);
}

 void Teste::messageLoginUserError(const QString &errorStr)
 {
    QString xml = parserToXML.loginUserError(errorStr);
    qDebug() << xml;
    parserFromXML.parser(xml);
 }

 void Teste::messageAddContact(const QString &contact, const QString &message)
 {
    QString xml = parserToXML.addContact(contact, message);
    qDebug() << xml;
    parserFromXML.parser(xml);
 }

void Teste::messageContactList(const QList<JagunMSNContact*>& list)
{
    QString xml = parserToXML.contactList(list);
    qDebug() << xml;
    parserFromXML.parser(xml);
}

void Teste::messageChangeStatus(const QString &nickname, const QString &message,
                               const QString &image, int status, const QList<QString> &sendToo)
{
    QString xml = parserToXML.changeStatus(nickname, message, image, status, sendToo);
    qDebug() << xml;
    parserFromXML.parser(xml);
}

void Teste::newUser(QString login, QString password, QString email)
{
    qDebug() << "Login : " << login;
    qDebug() << "Senha : " << password;
    qDebug() << "Email : " << email;
}

void Teste::userCreated(QString login, QDateTime date)
{
    qDebug() << "Login : " << login;
    qDebug() << "Data  :"  << date.toString("dd/mm/yyyy hh:mm:ss");
}

void Teste::userNotCreated(QString errorStr)
{
    qDebug() << "Erro :: " << errorStr;
}

void Teste::loginUser(QString login, QString password)
{
    qDebug() << "Login : " << login;
    qDebug() << "Senha : " << password;
}

void Teste::logOn(QString login, QString nickname, QString message, QString image, int status)
{
    qDebug() << "Login : " << login;
    qDebug() << "Nick : " << nickname;
    qDebug() << "Mensage, : " << message;
    qDebug() << "Imagem : " << image;
    qDebug() << "Status : " << status;
}

void Teste::loginUserError(QString errorStr)
{
    qDebug() << "Erro : " << errorStr;
}

void Teste::addContact(QString login, QString message)
{
    qDebug() << "Login : " << login;
    qDebug() << "Mensage, : " << message;
}

void Teste::contactList(QList<JagunMSNContact*> list)
{
    qDebug() << "Qtd contatos : " << list.size();
}

void Teste::changeStatus(QString nickname, QString message, QString image, int status, QStringList sendToo)
{
    qDebug() << "Nick : " << nickname;
    qDebug() << "Mensage, : " << message;
    qDebug() << "Imagem : " << image;
    qDebug() << "Status : " << status;
    qDebug() << "Qtd envia tambem : " << sendToo.size();
}
