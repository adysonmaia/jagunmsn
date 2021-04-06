#include "jagunparserfromxml.h"

void JagunParserFromXML::parser(const QString &xml)
{
    QString errorStr;
    int errorLine;
    int errorColumn;
    QDomDocument doc;

    if (!doc.setContent(xml,true,&errorStr,&errorLine,&errorColumn) )
    {
        qDebug() << "JagunParserFromXML :: erro no parsing | Li " << errorLine << " Col " << errorColumn << "  Msg " << errorStr;
        emit error(errorStr,errorLine,errorColumn);
        return;
    }

    QDomElement root = doc.documentElement();
    if (root.tagName() != "JagunMSN")
    {
        qDebug() << "JagunParserFromXML :: xml errado";
        return;
    }


    int code = -1;
    QDomNode node = root.firstChild();
    while ( !node.isNull() && code == -1 )
    {
        if ( node.toElement().tagName() == "Message"  ) {
            code = node.toElement().attribute("code").toInt();
        }
        node = node.nextSibling();
    }

    if (code == -1)
    {
        qDebug() << "JagunParserFromXML :: nao identificado codigo da mensagem";
        return;
    }

    switch (code)
    {
        case (JagunParserMessageInformation::ETPNewUser) :
            parserNewUser(xml);
            break;
        case (JagunParserMessageInformation::ETPUserCreated) :
            parserUserCreated(xml);
            break;
        case (JagunParserMessageInformation::ETPError) :
            parserErrorGeneral(xml);
            break;
        case (JagunParserMessageInformation::ETPLoginUser):
            parserLoginUser(xml);
            break;
        case (JagunParserMessageInformation::ETPLogOn) :
            parserLogOn(xml);
            break;
        case (JagunParserMessageInformation::ETPAddContact) :
            parserAddContact(xml);
            break;
        case (JagunParserMessageInformation::ETPRequestAddContact):
            parserRequestAddContact(xml);
            break;
        case (JagunParserMessageInformation::ETPAddContactConfirmation):
            parserAddContactConfirmation(xml);
            break;
        case (JagunParserMessageInformation::ETPApprovedAddContact):
            parserApprovedAddContact(xml);
            break;
        case (JagunParserMessageInformation::ETPRequestContactList):
            emit requestContactList();
            break;
        case (JagunParserMessageInformation::ETPContactList):
            parserContactList(xml);
            break;
        case (JagunParserMessageInformation::ETPRemoveContact):
            parserRemoveContact(xml);
            break;
        case (JagunParserMessageInformation::ETPBlockOrUnblock):
            parserBlock(xml);
            break;
        case (JagunParserMessageInformation::ETPChangeStatus):
            parserChangeStatus(xml);
            break;
        case (JagunParserMessageInformation::ETPGetStatusContact):
            parserGetStatusContact(xml);
            break;
        case (JagunParserMessageInformation::ETPChangeStatusContact):
            parserChangeStatusContact(xml);
            break;
        case (JagunParserMessageInformation::ETPKeepAlive):
            emit keepAlive();
            break;
        case (JagunParserMessageInformation::ETPSendMessage):
            parserSendMessage(xml);
            break;
        case (JagunParserMessageInformation::ETPReceiveMessage):
            parserReceiveMessage(xml);
            break;
        default :
            qDebug() << "JagunParserFromXML :: tipo de mensagem nao existe";
            return;
    }
}

void JagunParserFromXML::parserNewUser(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root.firstChild();

    QString login;
    QString password;
    QString email;
    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "NewUser"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if ( tagName == "login")
                {
                    login = childNode2.toText().data();
                }

                if (tagName == "password")
                {
                    password = childNode2.toText().data();
                }

                if (tagName == "email")
                {
                    email = childNode2.toText().data();
                }
                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }

    if ( login.length() == 0 || password.length() == 0 || email.length() == 0)
    {
        return;
    }


    emit newUser(login,password,email);
}

void JagunParserFromXML::parserUserCreated(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root.firstChild();

    QString login;
    uint time_t = 0;
    QDateTime date;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "UserCreated"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();

                if ( tagName == "login")
                {
                    login = childNode2.toText().data();
                }

                if ( tagName == "date")
                {
                    time_t = childNode2.toText().data().toUInt();
                }

                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }

    if ( login.length() == 0 || time_t == 0)
    {
        return;
    }

    date.setTime_t(time_t);
    emit userCreated(login,date);
}

void JagunParserFromXML::parserLoginUser(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root.firstChild();

    QString login;
    QString password;
    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "LoginUser"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if ( tagName == "login")
                {
                    login = childNode2.toText().data();
                }

                if (tagName == "password")
                {
                    password = childNode2.toText().data();
                }

                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }

    if ( login.length() == 0 || password.length() == 0 )
    {
        return;
    }

    emit loginUser(login,password);
}

void JagunParserFromXML::parserLogOn(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root.firstChild();

    QString login;
    QString nickname;
    QString message;
    QString image;
    int status = -1;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "LogOn"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if ( tagName == "login")
                {
                    login = childNode2.toText().data();
                }

                if (tagName == "nickname")
                {
                    nickname = childNode2.toText().data();
                }

                if (tagName == "message")
                {
                    message = childNode2.toText().data();
                }

                if (tagName == "image")
                {
                    image = childNode2.toText().data();
                }

                if (tagName == "status")
                {
                    status = childNode2.toText().data().toInt();
                }

                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }

    if ( login.length() == 0 || status == -1)
    {
        return;
    }
    emit logOn(login, nickname, message, image, status);
}

void JagunParserFromXML::parserAddContact(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root.firstChild();

    QString login;
    QString message;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "AddContact"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if ( tagName == "contact")
                {
                    login = childNode2.toText().data();
                }

                if (tagName == "message")
                {
                    message = childNode2.toText().data();
                }

                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }

    if ( login.length() == 0 )
    {
        return;
    }
    emit addContact(login,message);
}

void JagunParserFromXML::parserRequestAddContact(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root.firstChild();

    QString loginFrom;
    QString message;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "RequestAddContact"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if ( tagName == "from")
                {
                    loginFrom = childNode2.toText().data();
                }

                if (tagName == "message")
                {
                    message = childNode2.toText().data();
                }

                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }

    if ( loginFrom.length() == 0 )
    {
        return;
    }
    emit requestAddContact(loginFrom,message);
}

void JagunParserFromXML::parserAddContactConfirmation(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root.firstChild();

    QString loginTo;
    int confirmationInt = -1;
    bool confirmation;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "AddContactConfirmation"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if ( tagName == "to")
                {
                    loginTo = childNode2.toText().data();
                }

                if (tagName == "confirmation")
                {
                    confirmationInt = childNode2.toText().data().toInt();
                }

                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }

    if ( loginTo.length() == 0 || confirmationInt == -1)
    {
        return;
    }
    confirmation = (confirmationInt == 1);
    emit addContactConfirmation(loginTo, confirmation);
}

void JagunParserFromXML::parserApprovedAddContact(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root.firstChild();

    QString login;
    QString nickname;
    QString message;
    QString image;
    int status = -1;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "ApprovedAddContact"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if ( tagName == "login")
                {
                    login = childNode2.toText().data();
                }

                if (tagName == "nickname")
                {
                    nickname = childNode2.toText().data();
                }

                if (tagName == "message")
                {
                    message = childNode2.toText().data();
                }

                if (tagName == "image")
                {
                    image = childNode2.toText().data();
                }

                if (tagName == "status")
                {
                    status = childNode2.toText().data().toInt();
                }

                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }

    if ( login.length() == 0 || status == -1)
    {
        return;
    }
    emit approvedAddContact(login,nickname,message,image,status);
}

void JagunParserFromXML::parserContactList(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root.firstChild();

    QList<JagunMSNContact*> list;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "ContactList"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() )
            {
                if ( childNode.toElement().tagName() == "Contact")
                {
                    QDomNode childNode2 = childNode.firstChild();
                    JagunMSNContact *contact = new  JagunMSNContact();
                    list << contact;

                    while(!childNode2.isNull() )
                    {
                        QString tagName = childNode2.toElement().tagName();
                        QDomNode childNode3 = childNode2.firstChild();

                        if ( tagName == "login")
                        {
                            contact->setLogin(  childNode3.toText().data() );
                        }

                        if ( tagName == "nickname")
                        {
                            contact->setNickname( childNode3.toText().data() );
                        }

                        if ( tagName == "image")
                        {
                            contact->setImage( childNode3.toText().data() );
                        }

                        if ( tagName == "message")
                        {
                            contact->setMessage( childNode3.toText().data() );
                        }

                        if ( tagName == "email")
                        {
                            contact->setEmail( childNode3.toText().data() );
                        }

                        if ( tagName == "status")
                        {
                            int status = childNode3.toText().data().toInt();
                            contact->setStatus( JagunMSNContact::ECStatus(status )  );
                        }

                        if ( tagName == "blocked")
                        {
                            bool blocked = childNode3.toText().data().toInt();
                            contact->setBlocked(blocked);
                        }

                        childNode2 = childNode2.nextSibling();
                    }
                }
                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }

    if ( list.isEmpty() )
    {
        return;
    }

    emit contactList(list);
}


void JagunParserFromXML::parserRemoveContact(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root.firstChild();

    QString login;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "Remove"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if ( tagName == "to")
                {
                    login = childNode2.toText().data();
                }

                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }

    if ( login.length() == 0)
    {
        return;
    }
    emit removeContact(login);
}

void JagunParserFromXML::parserBlock(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root.firstChild();

    QString login;
    int blockType = -1;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "Block"  ) {
            QDomNode childNode = node.firstChild();
            blockType = node.toElement().attribute("type").toInt();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if ( tagName == "to")
                {
                    login = childNode2.toText().data();
                }

                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }

    if ( login.length() == 0 || blockType == -1)
    {
        return;
    }
    emit block(login,blockType);
}

void JagunParserFromXML::parserChangeStatus(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root.firstChild();

    QString nickname;
    QString message;
    QString image;
    int status = -1;
    QStringList sendToo;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "ChangeStatus"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if (tagName == "nickname")
                {
                    nickname = childNode2.toText().data();
                }

                if (tagName == "message")
                {
                    message = childNode2.toText().data();
                }

                if (tagName == "image")
                {
                    image = childNode2.toText().data();
                }

                if (tagName == "status")
                {
                    status = childNode2.toText().data().toInt();
                }

                if (tagName == "SendToo")
                {
                    childNode2 = childNode.firstChild();
                    while(!childNode2.isNull() ){
                        QString tagName = childNode2.toElement().tagName();
                        QDomNode childNode3 = childNode2.firstChild();
                        if (tagName == "to")
                        {
                            sendToo << childNode3.toText().data();
                        }

                        childNode2 = childNode2.nextSibling();
                    }
                }

                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }

    if ( nickname.length() == 0 || image.length() == 0 || status == -1)
    {
        return;
    }
    emit changeStatus(nickname,message,image,status,sendToo);
}

void JagunParserFromXML::parserGetStatusContact(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root.firstChild();

    QString login;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "GetStatusContact"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if ( tagName == "from")
                {
                    login = childNode2.toText().data();
                }

                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }

    if ( login.length() == 0)
    {
        return;
    }
    emit getStatusContact(login);
}

void JagunParserFromXML::parserChangeStatusContact(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root.firstChild();

    QString login;
    QString nickname;
    QString message;
    QString image;
    int status = -1;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "ChangeStatusContact"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if (tagName == "contact")
                {
                    login = childNode2.toText().data();
                }

                if (tagName == "nickname")
                {
                    nickname = childNode2.toText().data();
                }

                if (tagName == "message")
                {
                    message = childNode2.toText().data();
                }

                if (tagName == "image")
                {
                    image = childNode2.toText().data();
                }

                if (tagName == "status")
                {
                    status = childNode2.toText().data().toInt();
                }

                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }

    if ( login.length() == 0 || nickname.length() == 0 || image.length() == 0 || status == -1)
    {
        return;
    }
    emit changeStatusContact(login,nickname,message,image,status);
}

void JagunParserFromXML::parserSendMessage(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root.firstChild();

    QString message;
    QStringList sendTo;
    QDateTime dateSend;
    uint time_t = 0;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "SendMessage"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if (tagName == "message")
                {
                    message = childNode2.toText().data();
                }

                if (tagName == "dateSend")
                {
                    time_t = childNode2.toText().data().toInt();
                }

                if (tagName == "SendTo")
                {
                    childNode2 = childNode.firstChild();
                    while(!childNode2.isNull() ){
                        QString tagName = childNode2.toElement().tagName();
                        QDomNode childNode3 = childNode2.firstChild();
                        if (tagName == "to")
                        {
                            sendTo << childNode3.toText().data();
                        }

                        childNode2 = childNode2.nextSibling();
                    }
                }

                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }

    if (time_t == 0 || sendTo.size() == 0)
    {
        return;
    }
    dateSend.setTime_t(time_t);
    emit sendMessage(sendTo,message,dateSend);
}

void JagunParserFromXML::parserReceiveMessage(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root.firstChild();

    QString message;
    QString from;
    QStringList sendTo;
    QDateTime dateSend;
    uint time_t = 0;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "ReceiveMessage"  ) {
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();
                if (tagName == "message")
                {
                    message = childNode2.toText().data();
                }

                if (tagName == "from")
                {
                    from = childNode2.toText().data();
                }

                if (tagName == "dateSend")
                {
                    time_t = childNode2.toText().data().toInt();
                }

                if (tagName == "SendTo")
                {
                    childNode2 = childNode.firstChild();
                    while(!childNode2.isNull() ){
                        QString tagName = childNode2.toElement().tagName();
                        QDomNode childNode3 = childNode2.firstChild();
                        if (tagName == "to")
                        {
                            sendTo << childNode3.toText().data();
                        }

                        childNode2 = childNode2.nextSibling();
                    }
                }

                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }

    if (time_t == 0 || from.length() == 0)
    {
        return;
    }
    dateSend.setTime_t(time_t);

    emit receiveMessage(from,sendTo,message,dateSend);
}

void JagunParserFromXML::parserErrorGeneral(const QString &xml)
{
    QDomDocument doc;
    QDomElement root;
    QDomNode node;

    doc.setContent(xml,true);
    root = doc.documentElement();
    node = root.firstChild();

    QString errorStr;
    int codeError = -1;

    while ( !node.isNull() )
    {
        if ( node.toElement().tagName() == "Error"  )
        {
            codeError = node.toElement().attribute("code").toInt();
            QDomNode childNode = node.firstChild();
            while(!childNode.isNull() ){
                QString tagName = childNode.toElement().tagName();
                QDomNode childNode2 = childNode.firstChild();

                if (tagName == "instructions")
                {
                    errorStr = childNode2.toText().data();
                }

                childNode = childNode.nextSibling();
            }
        }
        node = node.nextSibling();
    }

    if (codeError == -1)
    {
        return;
    }

    switch (codeError)
    {
        case (JagunParserMessageInformation::EECNewUser):
            emit userNotCreated(errorStr);
            break;
        case (JagunParserMessageInformation::EECLoginUser):
            emit loginUserError(errorStr);
            break;
        case (JagunParserMessageInformation::EECAddContact):
            emit addContactError(errorStr);
            break;
        default:
            return;
    }
}
