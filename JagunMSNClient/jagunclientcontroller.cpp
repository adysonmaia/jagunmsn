#include "jagunclientcontroller.h"

JagunClientController::JagunClientController(const QHostAddress & address, quint16 port, QObject *parent)
                      : QObject(parent), addressHost(address), portHost(port)
{
    qRegisterMetaType< QList<JagunMSNContact*> >("QList<JagunMSNContact*>");

    connect(&parserFromXML, SIGNAL(userCreated(QString, QDateTime) ), this, SLOT(userCreated(QString, QDateTime) ) );
    connect(&parserFromXML, SIGNAL(userNotCreated(QString)), this, SLOT(userNotCreated(QString) )  );
    connect(&parserFromXML, SIGNAL(logOn(QString, QString, QString, QString, int) ), this, SLOT(logOn(QString, QString, QString, QString, int) )  );
    connect(&parserFromXML, SIGNAL(loginUserError(QString) ), this, SLOT(loginUserError(QString) ) );
    connect(&parserFromXML, SIGNAL(contactList(QList<JagunMSNContact*>) ), this, SIGNAL(contactList(QList<JagunMSNContact*>) ) );
    connect(&parserFromXML, SIGNAL(requestAddContact(QString, QString) ), this, SIGNAL(requestAddContact(QString, QString) ) );
    connect(&parserFromXML, SIGNAL(approvedAddContact(QString, QString, QString, QString, int) ), this, SLOT(approvedAddContact(QString, QString, QString, QString, int) ) );
    connect(&parserFromXML, SIGNAL(changeStatusContact(QString, QString, QString, QString, int) ), this, SLOT(changeStatusContact(QString, QString, QString, QString, int) ) );
    connect(&parserFromXML, SIGNAL(receiveMessage(QString, QStringList, QString, QDateTime) ), this, SIGNAL(receiveMessage(QString, QStringList, QString) ) );

    connect(&timerKeepAlive, SIGNAL(timeout() ), this, SLOT(keepAlive() ) );
    logged = false;
}

void JagunClientController::newUser(QString login,QString password,QString email)
{
    newUserLogin    = login;
    newUserPassword = password;
    newUserEmail    = email;

    socketNewUser = new JagunKET(this);

    connect(socketNewUser, SIGNAL(connected() ), this, SLOT(connectedNewUser() ) );
    connect(socketNewUser, SIGNAL(receive(QByteArray*) ), this, SLOT(receiveServer(QByteArray*) ) );
    connect(socketNewUser, SIGNAL(disconnected() ), this, SLOT(disconnectedNewUser() ) );
    connect(socketNewUser, SIGNAL(error(JagunKET::EErrorJagunKET) ), this, SLOT(errorServerNewUser(JagunKET::EErrorJagunKET) ) );

    socketNewUser->connectToHost(addressHost,portHost);
}

void JagunClientController::connectedNewUser()
{
    QString xml = parserToXML.newUser(newUserLogin, newUserPassword, newUserEmail);
    QByteArray message;
    message.append(xml);
    socketNewUser->send(&message);
}

void JagunClientController::disconnectedNewUser()
{
    newUserLogin    = "";
    newUserPassword = "";
    newUserEmail    = "";
    delete socketNewUser;
}

void JagunClientController::errorServerNewUser(JagunKET::EErrorJagunKET error)
{
    emit serverNotResponse();
    if (socketNewUser)
        socketNewUser->close();
}

void JagunClientController::userCreated(QString login, QDateTime date)
{
    emit successNewUser();
}

void JagunClientController::userNotCreated(QString errorStr)
{
    emit failureNewUser(errorStr);
}

void JagunClientController::loginUser(QString login, QString password)
{
    if (logged)
    {
        return;
    }

    this->userLogin    = login;
    this->userPassword = password;

    socket = new JagunKET(this);
    connect(socket, SIGNAL(connected() ), this, SLOT(connectedServer() ) );
    connect(socket, SIGNAL(receive(QByteArray*) ), this, SLOT(receiveServer(QByteArray*) ) );
    connect(socket, SIGNAL(disconnected() ), this, SLOT(disconnectedServer() ) );
    connect(socket, SIGNAL(error(JagunKET::EErrorJagunKET) ), this, SLOT(errorServer(JagunKET::EErrorJagunKET) ) );

    socket->connectToHost(addressHost,portHost);
}

void JagunClientController::connectedServer()
{
    logged = true;
    QString xml = parserToXML.loginUser(userLogin, userPassword);
    QByteArray message;
    message.append(xml);
    socket->send(&message);
    timerKeepAlive.start(TIME_KEEPALIVE);
}

void JagunClientController::receiveServer(QByteArray *data)
{
    QString xml(*data);
    parserFromXML.parser(xml);
}

void JagunClientController::disconnectedServer()
{
    qDebug() << "JagunClientController :: desconectado";
    timerKeepAlive.stop();
    logged = false;
    emit logoff();

    delete socket;
}

void JagunClientController::errorServer(JagunKET::EErrorJagunKET error)
{
    emit serverNotResponse();
    socket->close();
}

void JagunClientController::logOn(QString login, QString nickname, QString message, QString image, int status)
{
    qDebug() << "JagunClientController :: Logado";
    emit successloginUser(nickname, message, image, status);

    // requisita a lista de contatos
    QString xml = parserToXML.requestContactList();
    QByteArray messageSend;
    messageSend.append(xml);
    socket->send(&messageSend);
}

void JagunClientController::loginUserError(QString errorStr)
{
    qDebug() << "JagunClientController :: Falha ao logar";
    emit failureLoginUser(errorStr);
    //socket->close();
}

void JagunClientController::addContact(QString login, QString message)
{
    qDebug() << "JagunClientController :: Adicionar contato";
    QString xml = parserToXML.addContact(login,message);
    QByteArray messageSend;
    messageSend.append(xml);
    socket->send(&messageSend);
}

void JagunClientController::changeStatus(QString nickname, QString message, QString image, int status, QStringList sendToo)
{
    qDebug() << "JagunClientController :: Alterar status do usuario";
    QString xml = parserToXML.changeStatus(nickname, message, image, status, sendToo);
    QByteArray messageSend;
    messageSend.append(xml);
    socket->send(&messageSend);
}

void JagunClientController::addContactConfirmation(QString to, bool confirmation)
{
    qDebug() << "JagunClientController :: Confirmacao adicao do novo Contato";
    QString xml = parserToXML.addContactConfirmation(to,confirmation);
    QByteArray messageSend;
    messageSend.append(xml);
    socket->send(&messageSend);
}

void JagunClientController::approvedAddContact(QString login, QString nickname, QString message, QString image, int status)
{
    qDebug() << "JagunClientController :: Novo Contato";
    JagunMSNContact *contact = new JagunMSNContact();
    contact->setLogin(login);
    contact->setNickname(nickname);
    contact->setMessage(message);
    contact->setImage(image);
    contact->setStatus(  JagunMSNContact::ECStatus(status) );

    emit newContact(contact);
}

void JagunClientController::changeStatusContact(QString login, QString nickname, QString message, QString image, int status)
{

    qDebug() << "JagunClientController :: Contato alterou status";
    JagunMSNContact *contact = new JagunMSNContact();
    contact->setLogin(login);
    contact->setNickname(nickname);
    contact->setMessage(message);
    contact->setImage(image);
    contact->setStatus(  JagunMSNContact::ECStatus(status) );
    emit contactChangeStatus(contact);
}

void JagunClientController::keepAlive()
{
    qDebug() << "JagunClientController :: Enviando keepalive";
    QString xml = parserToXML.keepAlive();
    QByteArray messageSend;
    messageSend.append(xml);
    socket->send(&messageSend);
}

void JagunClientController::sendMessage(QStringList to, QString message)
{
    qDebug() << "JagunClientController:: Enviando uma mensagem de texto";
    QDateTime date = QDateTime::currentDateTime();
    QString xml = parserToXML.sendMessage(to,message,date);
    QByteArray messageSend;
    messageSend.append(xml);
    socket->send(&messageSend);
}
