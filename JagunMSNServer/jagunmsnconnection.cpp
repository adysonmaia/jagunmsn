#include "jagunmsnconnection.h"

JagunMSNConnection::JagunMSNConnection(JagunKETServer *parentServer,QUdpSocket *udpSocket, int lifeTime)
                   :JagunKETConnection(parentServer,udpSocket), time(lifeTime)
{
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    connect(this, SIGNAL(disconnected() ), this, SLOT(disconnectedConnection() ) );
    connect(this, SIGNAL(error(JagunKET::EErrorJagunKET) ), this, SLOT(errorConnection(JagunKET::EErrorJagunKET) ) );
    connect(this, SIGNAL(receive(QByteArray *)), this, SLOT(readClient(QByteArray *)) );

    connect(&lifeTimer, SIGNAL(timeout() ), this, SLOT(timeout() ) );
    connect(&parserFromXML, SIGNAL(newUser(QString, QString, QString)), this, SLOT(newUser(QString, QString, QString)) );
    connect(&parserFromXML, SIGNAL(loginUser(QString, QString)), this, SLOT(loginUser(QString, QString)) );
    connect(&parserFromXML, SIGNAL(requestContactList() ), this, SLOT(requestContactList() ) );
    connect(&parserFromXML, SIGNAL(changeStatus(QString, QString, QString, int, QStringList) ), this, SLOT(changeStatus(QString, QString, QString, int, QStringList) ) );
    connect(&parserFromXML, SIGNAL(addContact(QString, QString) ), this, SLOT(addContact(QString, QString) ) );
    connect(&parserFromXML, SIGNAL(addContactConfirmation(QString, bool) ), this, SLOT(addContactConfirmation(QString, bool) ) );
    connect(&parserFromXML, SIGNAL(sendMessage(QStringList, QString, QDateTime) ), this, SLOT(sendMessage(QStringList, QString, QDateTime) ) );

    //lifeTimer.start(time);
    logged = false;
    db.createNewConnection();
    //TODO - seta todas as id das conexoes no banco para -1
}

JagunMSNConnection* JagunMSNConnection::getOtherConnection(quint32 id)
{
    JagunMSNServer *server = qobject_cast<JagunMSNServer *> ( parent() );
    quint32 myConnection = getIdConnection();
    if (server && id != myConnection) {
        return server->getConnection(id);
    } else {
        return NULL;
    }
}

void JagunMSNConnection::setLifeTimer(int life)
{
    time = life;
}

void JagunMSNConnection::timeout()
{
//    qDebug() << "JagunMSNConnection :: LifeTime timeout";
//    //db.createNewConnection();
//    int status = (int) JagunMSNContact::ECSOffline;
//
//    QString nickname = db.getUsuNick(userLogin);
//    QString message  = db.getUsuMensagem(userLogin);
//    QString image    = db.getUsuImage(userLogin);
//    QStringList sendToo;
//
//    //db.closeConnection();
//    changeStatus(nickname, message, image, status, sendToo);
//
//    close();
}

void JagunMSNConnection::errorConnection(JagunKET::EErrorJagunKET error)
{
}

void JagunMSNConnection::disconnectedConnection()
{
    //TODO - se o usuario estiver conectado, salvar o status
    if (logged) {
         db.setIdConnection(userLogin,-1);
    }
    logged    = false;
    userLogin = "";

    delete this;
}

void JagunMSNConnection::readClient(QByteArray *data)
{
    //lifeTimer.stop();
    //lifeTimer.start(time);

    QString xml(*data);
    parserFromXML.parser(xml);
}

void JagunMSNConnection::newUser(QString login, QString password, QString email)
{
    qDebug() << "JagunMSNConnection :: criando nova conta";
    //db.createNewConnection();
    QString xml;
    if ( db.insertNewUser(login,email,password) ) {
        // Conta criada
        qDebug() << "JagunMSNConnection :: conta criada";
        QDateTime date = QDateTime::currentDateTime();
        xml = parserToXML.userCreated(login,date);
    } else {
        //Conta nao criada
        qDebug() << "JagunMSNConnection :: conta nao criada";
        QString errorStr( tr("Não foi possível criar conta") );
        xml = parserToXML.userNotCreated(errorStr);
    }

    QByteArray message;
    message.append(xml);
    send(&message);

    //db.closeConnection();
    close();
}

void JagunMSNConnection::loginUser(QString login, QString password)
{
    qDebug() << "JagunMSNConnection :: logando usuario";
    //db.createNewConnection();
    QString xml;
    if ( db.loginUser(login, password) )
    {
        qDebug() << "JagunMSNConnection :: usuario on";
        //Logado
        // pega os ultimos dados do usuario e armazena o id da conexao
        db.setIdConnection(login, getIdConnection());
        JagunMSNContact *userData = db.getData(login);

        QString nickname = userData->getNickname();
        QString message  = userData->getMessage();
        QString image    = userData->getImage();
        int status       = (int) userData->getLastStatus();
        if ( status == (int) JagunMSNContact::ECSOffline  ) {
            status = (int) JagunMSNContact::ECSOnline;
        }

        xml = parserToXML.logOn(login,nickname,message,image,status);

        logged     = true;
        userLogin  = login;
        userStatus = status;
    } else {
        qDebug() << "JagunMSNConnection :: usuario error";
        // Erro
        QString errorStr(tr("Login ou Senha inválida"));
        xml = parserToXML.loginUserError(errorStr);
    }

    QByteArray messageSend;
    messageSend.append(xml);
    send(&messageSend);

    if (logged) {
        JagunMSNContact *userData = db.getData(login);

        QString nickname = userData->getNickname();
        QString message  = userData->getMessage();
        QString image    = userData->getImage();
        int status       = (int) userData->getLastStatus();
        if ( status == (int) JagunMSNContact::ECSOffline  ) {
            status = (int) JagunMSNContact::ECSOnline;
        }
        QStringList sendToo;

        sendAllRequestAddContact();
        changeStatus(nickname,message,image,status,sendToo);
    } else {
        close();
    }
    //db.closeConnection();
}

void JagunMSNConnection::requestContactList()
{
    if (logged)
    {
        QList<JagunMSNContact*> listContact;
        //TODO - pegar a lista de contatos no banco, verifica se o contato nao bloqueiou o usuario

        listContact = db.getList(userLogin);
        for ( QList<JagunMSNContact*>::const_iterator it = listContact.begin(); it != listContact.end(); ++it )
        {
            JagunMSNContact *contact = (*it);
            QString contactLogin = contact->getLogin();
            //TODO - verifica se o contato bloqueou o usuario, muda seu status para offline
        }

        QString xml;
        xml = parserToXML.contactList(listContact);
        QByteArray messageSend;
        messageSend.append(xml);
        send(&messageSend);
    }
}

void JagunMSNConnection::addContact(QString loginAdd, QString message)
{
    if (!logged)
    {
        return;
    }

    qDebug() << "JagunMSNConnection :: adicionando contato " << userLogin << " - " << loginAdd << "  -  " << message;
    db.createNewConnection();
    if ( ! db.searchUser(loginAdd)  )
    {
        if ( db.checkContacts(userLogin,loginAdd) || db.checkContacts(loginAdd, userLogin) )
        {
            db.addContact(userLogin,loginAdd,message);
            quint32 idConnectionContact = db.getIdConnection(loginAdd);
            JagunMSNConnection *connectionContact = getOtherConnection(idConnectionContact);
            if (connectionContact)
            {
                QString xml = parserToXML.requestAddContact(userLogin,message);
                QByteArray messageSend;
                messageSend.append(xml);
                connectionContact->send(&messageSend);
            }
        } else {
            qDebug() << "JagunMSNConnection :: ja estava adicionado";
            JagunMSNContact *contact = db.getData(loginAdd);
            JagunMSNContact *user    = db.getData(userLogin);

            QString xml = parserToXML.changeStatusContact(contact->getLogin(),contact->getNickname(),
                                                          contact->getMessage(),contact->getImage(), (int) contact->getStatus());
            QByteArray messageSend;
            messageSend.append(xml);
            send(&messageSend);

            quint32 idConnectionContact = db.getIdConnection(loginAdd);
            JagunMSNConnection *connectionContact = getOtherConnection(idConnectionContact);

            if (connectionContact)
            {
                qDebug() << "JagunMSNConnection :: outro online";
                QString xmlTo = parserToXML.changeStatusContact(user->getLogin(), user->getNickname(),
                                                               user->getMessage(), user->getImage(), (int) user->getStatus() );
                QByteArray messageSendTo;
                messageSendTo.append(xmlTo);
                connectionContact->send(&messageSendTo);
            }
        }
    } else {
        QString errorStr(tr("Usuário não existe"));
        QString xml = parserToXML.addContactError(errorStr);
        QByteArray messageSend;
        messageSend.append(xml);
        send(&messageSend);
    }
    //db.closeConnection();
}


void JagunMSNConnection::addContactConfirmation(QString to, bool confirmation)
{
    if (!logged)
    {
        return;
    }

    qDebug() << "JagunMSNConnection :: confirmacao do adicionamento de contato";
    //db.createNewConnection();
    if (confirmation)
    {
        qDebug() << "JagunMSNConnection :: adicionar";
        db.acceptContact(userLogin,to);
        JagunMSNContact *contact = db.getData(to);
        JagunMSNContact *user    = db.getData(userLogin);

        QString contactNick    = contact->getNickname();
        QString contactMessage = contact->getMessage();
        QString contactIMage   = contact->getImage();
        int contactStatus      = (int) contact->getStatus();

        QString xml = parserToXML.approvedAddContact(to,contactNick, contactMessage, contactIMage, contactStatus);
        QByteArray messageSend;
        messageSend.append(xml);
        send(&messageSend);

        quint32 idConnectionContact = db.getIdConnection(to);
        JagunMSNConnection *connectionContact = getOtherConnection(idConnectionContact);

        if (connectionContact)
        {
            QString xmlTo = parserToXML.approvedAddContact(user->getLogin(), user->getNickname(),
                                                        user->getMessage(), user->getImage(), (int) user->getStatus() );
            QByteArray messageSendTo;
            messageSendTo.append(xmlTo);
            connectionContact->send(&messageSendTo);
        }

    } else {
        qDebug() << "JagunMSNConnection :: nao adicionar";
        db.dontAccept(userLogin,to);
    }
    //db.closeConnection();
}


void JagunMSNConnection::sendAllRequestAddContact()
{
    if (!logged)
    {
        return;
    }

    //db.createNewConnection();
    qDebug() << "JagunMSNConnection :: enviando pedidos de adicionar contatos pendentes";
    QList< QPair <QString,QString > > request = db.getUnconCont(userLogin);


    qDebug() << "JagunMSNConnection :: pendentes :" << request.size();

    for ( QList< QPair <QString,QString > >::const_iterator it = request.begin(); it != request.end(); ++it )
    {
        QString contact = (*it).first;
        QString message = db.getAddMsg(contact,userLogin);
        QString xml;

        xml = parserToXML.requestAddContact(contact,message);
        QByteArray messageSend;
        messageSend.append(xml);
        send(&messageSend);
    }
    qDebug() << "JagunMSNConnection :: terminou";
    //db.closeConnection();
}

void JagunMSNConnection::changeStatus(QString nickname, QString message, QString image, int status, QStringList sendToo)
{
    if (!logged)
    {
        return;
    }

    qDebug() << "JagunMSNConnection :: Mudanca de status do cliente";
    //db.createNewConnection();
    QList<JagunMSNContact *> listContact = db.getList(userLogin);

    db.setUsuNick(userLogin,nickname);
    db.setUsuImage(userLogin,image);
    db.setUsuStatus(userLogin,status);
    db.setUsuMensagem(userLogin,message);

    qDebug() << "JagunMSNConnection :: qtd de contatos " << listContact.size();
    for ( QList<JagunMSNContact*>::const_iterator it = listContact.begin(); it != listContact.end(); ++it )
    {
        QString contactLogin = (*it)->getLogin();
        quint32 idConnectionContact = db.getIdConnection(contactLogin);
        JagunMSNConnection *connectionContact = getOtherConnection(idConnectionContact);
        bool blocked = (*it)->isBlocked();

        //if (connectionContact && !blocked)
        if (connectionContact)
        {
            qDebug() << "JagunMSNConnection :: enviando status para um contato online ";
            QString xml = parserToXML.changeStatusContact(userLogin, nickname, message, image, status);
            QByteArray messageSend;
            messageSend.append(xml);
            connectionContact->send(&messageSend);
        }
    }

    for ( QStringList::const_iterator it = sendToo.begin(); it != sendToo.end(); ++it )
    {
        QString contactLogin = (*it);
        quint32 idConnectionContact = db.getIdConnection(contactLogin);
        JagunMSNConnection *connectionContact = getOtherConnection(idConnectionContact);

        if (connectionContact)
        {
            QString xml = parserToXML.changeStatusContact(userLogin, nickname, message, image, status);
            QByteArray messageSend;
            messageSend.append(xml);
            connectionContact->send(&messageSend);
        }
    }

    if ( status == JagunMSNContact::ECSOffline )
    {
        qDebug() << "JagunMSNConnection :: status offline";
        db.setIdConnection(userLogin,-1);
        //db.closeConnection();
        close();
    }
    else
    {
        //db.closeConnection();
    }
}

void JagunMSNConnection::sendMessage(QStringList listTo, QString message, QDateTime dateSend)
{
    if (!logged)
    {
        return;
    }
    listTo.removeDuplicates();

    QString loginTo;
    foreach (loginTo, listTo)
    {
        quint32 idConnectionContact = db.getIdConnection(loginTo);
        JagunMSNConnection *connectionContact = getOtherConnection(idConnectionContact);

        if (connectionContact)
        {
            QStringList sendToo(listTo);
            int index = sendToo.indexOf(loginTo);
            if (index > -1)
            {
                sendToo.removeAt(index);
            }
            QString xml = parserToXML.receiveMessage(userLogin,sendToo,message,dateSend);
            QByteArray messageSend;
            messageSend.append(xml);
            connectionContact->send(&messageSend);
        }
    }
}
