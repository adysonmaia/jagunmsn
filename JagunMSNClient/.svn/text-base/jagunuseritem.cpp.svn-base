#include "jagunuseritem.h"

JagunUserItem::JagunUserItem(QWidget *parent) : QWidget(parent)
{
    setupUi(this);
    lbUserStatus->clear();
    lbUserImage->clear();
    lbUserMessage->clear();
    lbUserName->clear();

}

void JagunUserItem::setStatusUser(JagunMSNContact::ECStatus status)
{
    this->status = status;
    QString iconName = QString(":/icons/%1").arg((int) status);
    lbUserStatus->setPixmap(QPixmap(iconName));
}

JagunMSNContact::ECStatus JagunUserItem::getStatusUser()
{
    return status;
}

void JagunUserItem::setImageUser(QString name)
{
    imgName = name;
    QString iconName = QString(":/user/resource/user/") + name + QString(".png");
    QPixmap icon(iconName);
    lbUserImage->setPixmap(icon.scaled(QSize(40,40),Qt::KeepAspectRatio,Qt::SmoothTransformation));
}

void JagunUserItem::setNameUser(QString name)
{
    lbUserName->setText(name);
}

void JagunUserItem::setMessageUser(QString message)
{
    lbUserMessage->setText(message);
}

QString JagunUserItem::getMessageUser()
{
    return lbUserMessage->text();
}

QString JagunUserItem::getNameUser()
{
    return lbUserName->text();
}

QString JagunUserItem::getImageUser()
{
    return imgName;
}

QString JagunUserItem::getLoginUser() {
    return login;
}

void JagunUserItem::setLoginUser(QString newLogin) {
    login=newLogin;
}
