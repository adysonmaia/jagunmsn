#include "jagunparsertoxml.h"

QString JagunParserToXML::newUser(const QString &login, const QString &password, const QString &email)
{
    int newUserCode = (int) JagunParserMessageInformation::ETPNewUser;
    QDomDocument doc;
    QDomElement root = doc.createElement("JagunMSN");
    doc.appendChild(root);

    QDomElement message = doc.createElement("Message");
    root.appendChild(message);
    QDomAttr code = doc.createAttribute("code");
    code.setValue(QString("%1").arg(newUserCode) );
    message.setAttributeNode(code);

    QDomElement nodeNewUser = doc.createElement("NewUser");
    root.appendChild(nodeNewUser);

    QDomElement nodeLogin = doc.createElement("login");
    nodeNewUser.appendChild(nodeLogin);
    QDomText nodeLoginText = doc.createTextNode(login);
    nodeLogin.appendChild(nodeLoginText);

    QDomElement nodePasswd = doc.createElement("password");
    nodeNewUser.appendChild(nodePasswd);
    QDomText nodePasswdText = doc.createTextNode(password);
    nodePasswd.appendChild(nodePasswdText);

    QDomElement nodeEmail = doc.createElement("email");
    nodeNewUser.appendChild(nodeEmail);
    QDomText nodeEmailText = doc.createTextNode(email);
    nodeEmail.appendChild(nodeEmailText);


    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;
}

QString JagunParserToXML::userCreated(const QString &login, const QDateTime &date)
{
    int userCreatedCode = (int) JagunParserMessageInformation::ETPUserCreated;
    QDomDocument doc;
    QDomElement root = doc.createElement("JagunMSN");
    doc.appendChild(root);

    QDomElement message = doc.createElement("Message");
    root.appendChild(message);
    QDomAttr code = doc.createAttribute("code");
    code.setValue(QString("%1").arg(userCreatedCode) );
    message.setAttributeNode(code);

    QDomElement nodeUserCreated = doc.createElement("UserCreated");
    root.appendChild(nodeUserCreated);

    QDomElement nodeLogin = doc.createElement("login");
    nodeUserCreated.appendChild(nodeLogin);
    QDomText nodeLoginText = doc.createTextNode(login);
    nodeLogin.appendChild(nodeLoginText);

    QDomElement nodeDate = doc.createElement("date");
    nodeUserCreated.appendChild(nodeDate);
    // retorna a quantidade de segundos passados desde 1970-01-01T00:00:00
    uint date_t = date.toTime_t();
    QDomText nodeDateText = doc.createTextNode( QString("%1").arg(date_t) );
    nodeDate.appendChild(nodeDateText);

    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;
}

QString JagunParserToXML::userNotCreated(const QString &errorStr)
{
    return messageErrorGeneral(JagunParserMessageInformation::EECNewUser, errorStr);
}

QString JagunParserToXML::loginUser(const QString &login, const QString &password)
{
    int MessageCode = (int) JagunParserMessageInformation::ETPLoginUser;
    QDomDocument doc;
    QDomElement root = doc.createElement("JagunMSN");
    doc.appendChild(root);

    QDomElement message = doc.createElement("Message");
    root.appendChild(message);
    QDomAttr code = doc.createAttribute("code");
    code.setValue(QString("%1").arg(MessageCode) );
    message.setAttributeNode(code);

    QDomElement nodeLoginUser = doc.createElement("LoginUser");
    root.appendChild(nodeLoginUser);

    QDomElement nodeLogin = doc.createElement("login");
    nodeLoginUser.appendChild(nodeLogin);
    QDomText nodeLoginText = doc.createTextNode(login);
    nodeLogin.appendChild(nodeLoginText);

    QDomElement nodePasswd = doc.createElement("password");
    nodeLoginUser.appendChild(nodePasswd);
    QDomText nodePasswdText = doc.createTextNode(password);
    nodePasswd.appendChild(nodePasswdText);

    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;
}

QString JagunParserToXML::logOn(const QString &login, const QString &nickname, const QString &message, const QString &image, int status)
{
    int MessageCode = (int) JagunParserMessageInformation::ETPLogOn;
    QDomDocument doc;
    QDomElement root = doc.createElement("JagunMSN");
    doc.appendChild(root);

    QDomElement messageType = doc.createElement("Message");
    root.appendChild(messageType);
    QDomAttr code = doc.createAttribute("code");
    code.setValue(QString("%1").arg(MessageCode) );
    messageType.setAttributeNode(code);

    QDomElement nodeLogOn = doc.createElement("LogOn");
    root.appendChild(nodeLogOn);

    QDomElement nodeLogin = doc.createElement("login");
    nodeLogOn.appendChild(nodeLogin);
    QDomText nodeLoginText = doc.createTextNode(login);
    nodeLogin.appendChild(nodeLoginText);

    QDomElement nodeNickname = doc.createElement("nickname");
    nodeLogOn.appendChild(nodeNickname);
    QDomText nodeNicknameText = doc.createTextNode(nickname);
    nodeNickname.appendChild(nodeNicknameText);

    QDomElement nodeMessage = doc.createElement("message");
    nodeLogOn.appendChild(nodeMessage);
    QDomText nodeMessageText = doc.createTextNode(message);
    nodeMessage.appendChild(nodeMessageText);

    QDomElement nodeImage = doc.createElement("image");
    nodeLogOn.appendChild(nodeImage);
    QDomText nodeImageText = doc.createTextNode(image);
    nodeImage.appendChild(nodeImageText);

    QDomElement nodeStatus = doc.createElement("status");
    nodeLogOn.appendChild(nodeStatus);
    QDomText nodeStatusText = doc.createTextNode(QString("%1").arg(status) );
    nodeStatus.appendChild(nodeStatusText);

    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;
}

QString JagunParserToXML::loginUserError(const QString &errorStr)
{
    return messageErrorGeneral(JagunParserMessageInformation::EECLoginUser, errorStr);
}

QString JagunParserToXML::addContact(const QString &contact, const QString &message)
{
    int MessageCode = (int) JagunParserMessageInformation::ETPAddContact;
    QDomDocument doc;
    QDomElement root = doc.createElement("JagunMSN");
    doc.appendChild(root);

    QDomElement messageType = doc.createElement("Message");
    root.appendChild(messageType);
    QDomAttr code = doc.createAttribute("code");
    code.setValue(QString("%1").arg(MessageCode) );
    messageType.setAttributeNode(code);

    QDomElement nodeAddContact = doc.createElement("AddContact");
    root.appendChild(nodeAddContact);

    QDomElement nodeContact = doc.createElement("contact");
    nodeAddContact.appendChild(nodeContact);
    QDomText nodeContactText = doc.createTextNode(contact);
    nodeContact.appendChild(nodeContactText);

    QDomElement nodeMessage = doc.createElement("message");
    nodeAddContact.appendChild(nodeMessage);
    QDomText nodeMessageText = doc.createTextNode(message);
    nodeMessage.appendChild(nodeMessageText);

    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;
}

QString JagunParserToXML::addContactError(const QString &errorStr)
{
    return messageErrorGeneral(JagunParserMessageInformation::EECAddContact, errorStr);
}

QString JagunParserToXML::requestAddContact(const QString &from, const QString &message)
{
    int MessageCode = (int) JagunParserMessageInformation::ETPRequestAddContact;
    QDomDocument doc;
    QDomElement root = doc.createElement("JagunMSN");
    doc.appendChild(root);

    QDomElement messageType = doc.createElement("Message");
    root.appendChild(messageType);
    QDomAttr code = doc.createAttribute("code");
    code.setValue(QString("%1").arg(MessageCode) );
    messageType.setAttributeNode(code);

    QDomElement nodeRequestAddContact = doc.createElement("RequestAddContact");
    root.appendChild(nodeRequestAddContact);

    QDomElement nodeFrom = doc.createElement("from");
    nodeRequestAddContact.appendChild(nodeFrom);
    QDomText nodeFromText = doc.createTextNode(from);
    nodeFrom.appendChild(nodeFromText);

    QDomElement nodeMessage = doc.createElement("message");
    nodeRequestAddContact.appendChild(nodeMessage);
    QDomText nodeMessageText = doc.createTextNode(message);
    nodeMessage.appendChild(nodeMessageText);

    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;
}

QString JagunParserToXML::addContactConfirmation(const QString &to, bool confirmation)
{
    int MessageCode = (int) JagunParserMessageInformation::ETPAddContactConfirmation;
    QDomDocument doc;
    QDomElement root = doc.createElement("JagunMSN");
    doc.appendChild(root);

    QDomElement messageType = doc.createElement("Message");
    root.appendChild(messageType);
    QDomAttr code = doc.createAttribute("code");
    code.setValue(QString("%1").arg(MessageCode) );
    messageType.setAttributeNode(code);

    QDomElement AddContactConfirmation = doc.createElement("AddContactConfirmation");
    root.appendChild(AddContactConfirmation);

    QDomElement nodeTo = doc.createElement("to");
    AddContactConfirmation.appendChild(nodeTo);
    QDomText nodeToText = doc.createTextNode(to);
    nodeTo.appendChild(nodeToText);

    QString confirmationStr = (confirmation) ? "1" : "0";

    QDomElement nodeConfirmation = doc.createElement("confirmation");
    AddContactConfirmation.appendChild(nodeConfirmation);
    QDomText nodeConfirmationText = doc.createTextNode(confirmationStr);
    nodeConfirmation.appendChild(nodeConfirmationText);

    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;
}

QString JagunParserToXML::approvedAddContact(const QString &login, const QString &nickname, const QString &message, const QString &image, int status)
{
    int MessageCode = (int) JagunParserMessageInformation::ETPApprovedAddContact;
    QDomDocument doc;
    QDomElement root = doc.createElement("JagunMSN");
    doc.appendChild(root);

    QDomElement messageType = doc.createElement("Message");
    root.appendChild(messageType);
    QDomAttr code = doc.createAttribute("code");
    code.setValue(QString("%1").arg(MessageCode) );
    messageType.setAttributeNode(code);

    QDomElement nodeApprovedAdd = doc.createElement("ApprovedAddContact");
    root.appendChild(nodeApprovedAdd);

    QDomElement nodeLogin = doc.createElement("login");
    nodeApprovedAdd.appendChild(nodeLogin);
    QDomText nodeLoginText = doc.createTextNode(login);
    nodeLogin.appendChild(nodeLoginText);

    QDomElement nodeNickname = doc.createElement("nickname");
    nodeApprovedAdd.appendChild(nodeNickname);
    QDomText nodeNicknameText = doc.createTextNode(nickname);
    nodeNickname.appendChild(nodeNicknameText);

    QDomElement nodeMessage = doc.createElement("message");
    nodeApprovedAdd.appendChild(nodeMessage);
    QDomText nodeMessageText = doc.createTextNode(message);
    nodeMessage.appendChild(nodeMessageText);

    QDomElement nodeImage = doc.createElement("image");
    nodeApprovedAdd.appendChild(nodeImage);
    QDomText nodeImageText = doc.createTextNode(image);
    nodeImage.appendChild(nodeImageText);

    QDomElement nodeStatus = doc.createElement("status");
    nodeApprovedAdd.appendChild(nodeStatus);
    QDomText nodeStatusText = doc.createTextNode(QString("%1").arg(status) );
    nodeStatus.appendChild(nodeStatusText);

    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;
}

QString JagunParserToXML::messageErrorGeneral(JagunParserMessageInformation::EErrorCode code, const QString &errorStr)
{
    int errorCode        = (int) code;
    int messageErrorCode = (int) JagunParserMessageInformation::ETPError;
    QDomDocument doc;
    QDomElement root = doc.createElement("JagunMSN");
    doc.appendChild(root);

    QDomElement message = doc.createElement("Message");
    root.appendChild(message);
    QDomAttr messageCode = doc.createAttribute("code");
    messageCode.setValue(QString("%1").arg(messageErrorCode) );
    message.setAttributeNode(messageCode);

    QDomElement nodeError = doc.createElement("Error");
    root.appendChild(nodeError);
    QDomAttr nodeErrorCode = doc.createAttribute("code");
    nodeErrorCode.setValue(QString("%1").arg(errorCode) );
    nodeError.setAttributeNode(nodeErrorCode);

    QDomElement nodeInstructions = doc.createElement("instructions");
    nodeError.appendChild(nodeInstructions);
    QDomText nodeInstructionsText = doc.createTextNode(errorStr);
    nodeInstructions.appendChild(nodeInstructionsText);

    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;
}

QString JagunParserToXML::requestContactList()
{
    int MessageCode = (int) JagunParserMessageInformation::ETPRequestContactList;
    QDomDocument doc;
    QDomElement root = doc.createElement("JagunMSN");
    doc.appendChild(root);

    QDomElement messageType = doc.createElement("Message");
    root.appendChild(messageType);
    QDomAttr code = doc.createAttribute("code");
    code.setValue(QString("%1").arg(MessageCode) );
    messageType.setAttributeNode(code);

    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;
}

QString JagunParserToXML::contactList(const QList<JagunMSNContact*> &list)
{
    int MessageCode = (int) JagunParserMessageInformation::ETPContactList;
    QDomDocument doc;
    QDomElement root = doc.createElement("JagunMSN");
    doc.appendChild(root);

    QDomElement messageType = doc.createElement("Message");
    root.appendChild(messageType);
    QDomAttr code = doc.createAttribute("code");
    code.setValue(QString("%1").arg(MessageCode) );
    messageType.setAttributeNode(code);

    QDomElement nodeContactList = doc.createElement("ContactList");
    root.appendChild(nodeContactList);

    for ( QList<JagunMSNContact*>::const_iterator it = list.begin(); it != list.end(); ++it )
    {
        QDomElement nodeContact = doc.createElement("Contact");
        nodeContactList.appendChild(nodeContact);

        QString login = (*it)->getLogin();
        QString nick  = (*it)->getNickname();
        QString img   = (*it)->getImage();
        QString msg   = (*it)->getMessage();
        QString email = (*it)->getEmail();
        int status    = (int) (*it)->getStatus();
        int blocked   = (*it)->isBlocked();

        QDomElement nodeLogin = doc.createElement("login");
        nodeContact.appendChild(nodeLogin);
        QDomText nodeLoginText = doc.createTextNode(login);
        nodeLogin.appendChild(nodeLoginText);

        QDomElement nodeNick = doc.createElement("nickname");
        nodeContact.appendChild(nodeNick);
        QDomText nodeNickText = doc.createTextNode(nick);
        nodeNick.appendChild(nodeNickText);

        QDomElement nodeImage = doc.createElement("image");
        nodeContact.appendChild(nodeImage);
        QDomText nodeImageText = doc.createTextNode(img);
        nodeImage.appendChild(nodeImageText);

        QDomElement nodeMessage = doc.createElement("message");
        nodeContact.appendChild(nodeMessage);
        QDomText nodeMessageText = doc.createTextNode(msg);
        nodeMessage.appendChild(nodeMessageText);

        QDomElement nodeEmail = doc.createElement("email");
        nodeContact.appendChild(nodeEmail);
        QDomText nodeEmailText = doc.createTextNode(email);
        nodeEmail.appendChild(nodeEmailText);

        QDomElement nodeStatus = doc.createElement("status");
        nodeContact.appendChild(nodeStatus);
        QDomText nodeStatusText = doc.createTextNode(QString("%1").arg(status));
        nodeStatus.appendChild(nodeStatusText);

        QDomElement nodeBlocked = doc.createElement("blocked");
        nodeContact.appendChild(nodeBlocked);
        QDomText nodeBlockedText = doc.createTextNode(QString("%1").arg(blocked));
        nodeBlocked.appendChild(nodeBlockedText);
    }

    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;
}

QString JagunParserToXML::removeContact(const QString& login)
{
    int MessageCode = (int) JagunParserMessageInformation::ETPRemoveContact;
    QDomDocument doc;
    QDomElement root = doc.createElement("JagunMSN");
    doc.appendChild(root);

    QDomElement messageType = doc.createElement("Message");
    root.appendChild(messageType);
    QDomAttr code = doc.createAttribute("code");
    code.setValue(QString("%1").arg(MessageCode) );
    messageType.setAttributeNode(code);

    QDomElement nodeRemove = doc.createElement("Remove");
    root.appendChild(nodeRemove);

    QDomElement nodeTo = doc.createElement("to");
    nodeRemove.appendChild(nodeTo);
    QDomText nodeToText = doc.createTextNode(login);
    nodeTo.appendChild(nodeToText);

    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;
}

QString JagunParserToXML::block(const QString& login, bool block)
{
    int MessageCode = (int) JagunParserMessageInformation::ETPBlockOrUnblock;
    QDomDocument doc;
    QDomElement root = doc.createElement("JagunMSN");
    doc.appendChild(root);

    QDomElement messageType = doc.createElement("Message");
    root.appendChild(messageType);
    QDomAttr code = doc.createAttribute("code");
    code.setValue(QString("%1").arg(MessageCode) );
    messageType.setAttributeNode(code);

    QDomElement nodeBlock = doc.createElement("Block");
    root.appendChild(nodeBlock);
    QDomAttr blockType = doc.createAttribute("type");
    blockType.setValue(QString("%1").arg( (int) block) );
    nodeBlock.setAttributeNode(blockType);

    QDomElement nodeTo = doc.createElement("to");
    nodeBlock.appendChild(nodeTo);
    QDomText nodeToText = doc.createTextNode(login);
    nodeTo.appendChild(nodeToText);

    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;
}

QString JagunParserToXML::changeStatus(const QString &nickname, const QString &message,
                                       const QString &image, int status, const QStringList &sendToo)
{
    int MessageCode = (int) JagunParserMessageInformation::ETPChangeStatus;
    QDomDocument doc;
    QDomElement root = doc.createElement("JagunMSN");
    doc.appendChild(root);

    QDomElement messageType = doc.createElement("Message");
    root.appendChild(messageType);
    QDomAttr code = doc.createAttribute("code");
    code.setValue(QString("%1").arg(MessageCode) );
    messageType.setAttributeNode(code);

    QDomElement nodeChangeStatus = doc.createElement("ChangeStatus");
    root.appendChild(nodeChangeStatus);

    QDomElement nodeNickname = doc.createElement("nickname");
    nodeChangeStatus.appendChild(nodeNickname);
    QDomText nodeNicknameText = doc.createTextNode(nickname);
    nodeNickname.appendChild(nodeNicknameText);

    QDomElement nodeMessage = doc.createElement("message");
    nodeChangeStatus.appendChild(nodeMessage);
    QDomText nodeMessageText = doc.createTextNode(message);
    nodeMessage.appendChild(nodeMessageText);

    QDomElement nodeImage = doc.createElement("image");
    nodeChangeStatus.appendChild(nodeImage);
    QDomText nodeImageText = doc.createTextNode(image);
    nodeImage.appendChild(nodeImageText);

    QDomElement nodeStatus = doc.createElement("status");
    nodeChangeStatus.appendChild(nodeStatus);
    QDomText nodeStatusText = doc.createTextNode(QString("%1").arg(status) );
    nodeStatus.appendChild(nodeStatusText);

    if (!sendToo.isEmpty() ) {
        QDomElement nodeSendToo = doc.createElement("SendToo");
        nodeChangeStatus.appendChild(nodeSendToo);

        for ( QStringList::const_iterator it = sendToo.begin(); it != sendToo.end(); ++it )
        {
            QString to = (*it);
            QDomElement nodeTo = doc.createElement("to");
            nodeSendToo.appendChild(nodeTo);
            QDomText nodeToText = doc.createTextNode(to);
            nodeTo.appendChild(nodeToText);
        }
    }

    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;
}

QString JagunParserToXML::getStatusContact(const QString &login)
{
    int MessageCode = (int) JagunParserMessageInformation::ETPGetStatusContact;
    QDomDocument doc;
    QDomElement root = doc.createElement("JagunMSN");
    doc.appendChild(root);

    QDomElement messageType = doc.createElement("Message");
    root.appendChild(messageType);
    QDomAttr code = doc.createAttribute("code");
    code.setValue(QString("%1").arg(MessageCode) );
    messageType.setAttributeNode(code);

    QDomElement nodeGetStatus = doc.createElement("GetStatusContact");
    root.appendChild(nodeGetStatus);

    QDomElement nodeFrom = doc.createElement("from");
    nodeGetStatus.appendChild(nodeFrom);
    QDomText nodeFromText = doc.createTextNode(login);
    nodeFrom.appendChild(nodeFromText);

    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;
}

QString JagunParserToXML::changeStatusContact(const QString &login, const QString &nickname, const QString &message, const QString &image, int status)
{
    int MessageCode = (int) JagunParserMessageInformation::ETPChangeStatusContact;
    QDomDocument doc;
    QDomElement root = doc.createElement("JagunMSN");
    doc.appendChild(root);

    QDomElement messageType = doc.createElement("Message");
    root.appendChild(messageType);
    QDomAttr code = doc.createAttribute("code");
    code.setValue(QString("%1").arg(MessageCode) );
    messageType.setAttributeNode(code);

    QDomElement nodeChangeStatus = doc.createElement("ChangeStatusContact");
    root.appendChild(nodeChangeStatus);

    QDomElement nodeContact = doc.createElement("contact");
    nodeChangeStatus.appendChild(nodeContact);
    QDomText nodeContactText = doc.createTextNode(login);
    nodeContact.appendChild(nodeContactText);

    QDomElement nodeNickname = doc.createElement("nickname");
    nodeChangeStatus.appendChild(nodeNickname);
    QDomText nodeNicknameText = doc.createTextNode(nickname);
    nodeNickname.appendChild(nodeNicknameText);

    QDomElement nodeMessage = doc.createElement("message");
    nodeChangeStatus.appendChild(nodeMessage);
    QDomText nodeMessageText = doc.createTextNode(message);
    nodeMessage.appendChild(nodeMessageText);

    QDomElement nodeImage = doc.createElement("image");
    nodeChangeStatus.appendChild(nodeImage);
    QDomText nodeImageText = doc.createTextNode(image);
    nodeImage.appendChild(nodeImageText);

    QDomElement nodeStatus = doc.createElement("status");
    nodeChangeStatus.appendChild(nodeStatus);
    QDomText nodeStatusText = doc.createTextNode(QString("%1").arg(status) );
    nodeStatus.appendChild(nodeStatusText);

    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;
}

QString JagunParserToXML::keepAlive()
{
    int MessageCode = (int) JagunParserMessageInformation::ETPKeepAlive;
    QDomDocument doc;
    QDomElement root = doc.createElement("JagunMSN");
    doc.appendChild(root);

    QDomElement messageType = doc.createElement("Message");
    root.appendChild(messageType);
    QDomAttr code = doc.createAttribute("code");
    code.setValue(QString("%1").arg(MessageCode) );
    messageType.setAttributeNode(code);

    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;
}

QString JagunParserToXML::sendMessage(const QStringList& listTo, const QString& message, const QDateTime &dateSend)
{
    int MessageCode = (int) JagunParserMessageInformation::ETPSendMessage;
    QDomDocument doc;
    QDomElement root = doc.createElement("JagunMSN");
    doc.appendChild(root);

    QDomElement messageType = doc.createElement("Message");
    root.appendChild(messageType);
    QDomAttr code = doc.createAttribute("code");
    code.setValue(QString("%1").arg(MessageCode) );
    messageType.setAttributeNode(code);

    QDomElement nodeSendMessage = doc.createElement("SendMessage");
    root.appendChild(nodeSendMessage);

    QDomElement nodeSendTo = doc.createElement("SendTo");
    nodeSendMessage.appendChild(nodeSendTo);

    QString loginTo;
    foreach (loginTo, listTo)
    {
        QDomElement nodeTo = doc.createElement("to");
        nodeSendTo.appendChild(nodeTo);
        QDomText nodeToText = doc.createTextNode(loginTo);
        nodeTo.appendChild(nodeToText);
    }

    QDomElement nodeDate = doc.createElement("dateSend");
    nodeSendMessage.appendChild(nodeDate);
    // retorna a quantidade de segundos passados desde 1970-01-01T00:00:00
    uint date_t = dateSend.toTime_t();
    QDomText nodeDateText = doc.createTextNode( QString("%1").arg(date_t) );
    nodeDate.appendChild(nodeDateText);

    QDomElement nodeMessage = doc.createElement("message");
    nodeSendMessage.appendChild(nodeMessage);
    QDomText nodeMessageText = doc.createTextNode(message);
    nodeMessage.appendChild(nodeMessageText);

    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;
}

QString JagunParserToXML::receiveMessage(const QString &from, const QStringList& listTo, const QString& message, const QDateTime &dateSend)
{
    int MessageCode = (int) JagunParserMessageInformation::ETPReceiveMessage;
    QDomDocument doc;
    QDomElement root = doc.createElement("JagunMSN");
    doc.appendChild(root);

    QDomElement messageType = doc.createElement("Message");
    root.appendChild(messageType);
    QDomAttr code = doc.createAttribute("code");
    code.setValue(QString("%1").arg(MessageCode) );
    messageType.setAttributeNode(code);

    QDomElement nodeReceiveMessage = doc.createElement("ReceiveMessage");
    root.appendChild(nodeReceiveMessage);

    QDomElement nodeFrom = doc.createElement("from");
    nodeReceiveMessage.appendChild(nodeFrom);
    QDomText nodeFromText = doc.createTextNode(from);
    nodeFrom.appendChild(nodeFromText);

    QDomElement nodeSendTo = doc.createElement("SendTo");
    nodeReceiveMessage.appendChild(nodeSendTo);

    QString loginTo;
    foreach (loginTo, listTo)
    {
        QDomElement nodeTo = doc.createElement("to");
        nodeSendTo.appendChild(nodeTo);
        QDomText nodeToText = doc.createTextNode(loginTo);
        nodeTo.appendChild(nodeToText);
    }

    QDomElement nodeDate = doc.createElement("dateSend");
    nodeReceiveMessage.appendChild(nodeDate);
    // retorna a quantidade de segundos passados desde 1970-01-01T00:00:00
    uint date_t = dateSend.toTime_t();
    QDomText nodeDateText = doc.createTextNode( QString("%1").arg(date_t) );
    nodeDate.appendChild(nodeDateText);

    QDomElement nodeMessage = doc.createElement("message");
    nodeReceiveMessage.appendChild(nodeMessage);
    QDomText nodeMessageText = doc.createTextNode(message);
    nodeMessage.appendChild(nodeMessageText);

    QDomNode xmlNode = doc.createProcessingInstruction("xml",
                           "version=\"1.0\" encoding=\"UTF-8\"");
    doc.insertBefore(xmlNode, doc.firstChild());

    const int Indent = 0;
    QString xml;
    QTextStream out(&xml);
    doc.save(out, Indent);

    return xml;
}
