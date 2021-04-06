#include "jagunchatuseritem.h"

JagunChatUserItem::JagunChatUserItem(QWidget *parent) : QWidget(parent)
{
    setupUi(this);
}

void JagunChatUserItem::setImageUser(QString name)
{
    QString iconName = QString(":/user/resource/user/") + name + QString(".png");
    QPixmap icon(iconName);
    lbUserImage->setPixmap(icon);
}

void JagunChatUserItem::setNameUser(QString name)
{
    lbUserName->setText(name);
}

QString JagunChatUserItem::getNameUser()
{
    return lbUserName->text();
}

void JagunChatUserItem::setStatusUser(JagunMSNContact::ECStatus newStatus)
{
    status = newStatus;
    // checa o status e muda a cor de fundo
}

void JagunChatUserItem::setLoginUser(QString newLogin)
{
    login = newLogin;
}

QString JagunChatUserItem::getLoginUser()
{
    return login;
}

void JagunChatUserItem::setMessageUser(QString newMessage)
{
    message = newMessage;
}

QString JagunChatUserItem::getMessageUser()
{
    return message;
}

void JagunChatUserItem::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        retranslateUi(this);
        break;
    default:
        break;
    }
}
