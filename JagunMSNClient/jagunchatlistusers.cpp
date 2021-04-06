#include "jagunchatlistusers.h"
#include "jagunchatuseritem.h"
#include "jagunmsncontact.h"

JagunChatListUsers::JagunChatListUsers(QWidget *parent) : QListWidget(parent)
{

}

void JagunChatListUsers::addGuest(QString login, QString name,QString imageName, QString message, JagunMSNContact::ECStatus status)
{
    QListWidgetItem *item = new QListWidgetItem(this);
    //item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    JagunChatUserItem *user = new JagunChatUserItem(this);
    user->setEnabled(true);
    //user->focusPolicy(Qt::NoFocus);
    user->setStatusUser(status);
    user->setImageUser(imageName);
    user->setNameUser(name);
    user->setLoginUser(login);
    user->setMessageUser(message);

    QSize s;
    s.setHeight(user->height());
    item->setSizeHint(s);
    setIndexWidget(indexFromItem(item),user);
}

bool JagunChatListUsers::containsGuest(QString login)
{
    QListWidgetItem *item = 0;
    JagunChatUserItem *user = 0;

    for(int i = 0; i < this->count(); i++)
    {
        item = this->item(i);
        user = qobject_cast<JagunChatUserItem*>(this->itemWidget(item));
        if ( login == user->getLoginUser() )
        {
            return true;
        }
    }
    return false;
}
void JagunChatListUsers::setStateGuest(QString login, QString name,QString imageName, QString message, JagunMSNContact::ECStatus status)
{
    QListWidgetItem *item = 0;
    JagunChatUserItem *user = 0;

    for(int i = 0; i < this->count(); i++)
    {
        item = this->item(i);
        user = qobject_cast<JagunChatUserItem*>(this->itemWidget(item));
        if ( login == user->getLoginUser()  )
        {
            user->setNameUser(name);
            user->setImageUser(imageName);
            user->setMessageUser(message);
            user->setStatusUser(status);
        }
    }
}

JagunChatUserItem* JagunChatListUsers::getItem(QString login)
{
    QListWidgetItem *item = 0;
    JagunChatUserItem *user = 0;

    for(int i = 0; i < this->count(); i++)
    {
        item = this->item(i);
        user = qobject_cast<JagunChatUserItem*>(this->itemWidget(item));
        if ( login == user->getLoginUser()  )
        {
            return user;
        }
    }
    return user;
}
