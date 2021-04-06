#include "jagunlistusers.h"
#include "jagunuseritem.h"
#include "jagunmsncontact.h"

JagunListUsers::JagunListUsers(QWidget *parent) : QListWidget(parent)
{
    /*
    QListWidgetItem *item = new QListWidgetItem(this);
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    JagunUserItem *user = new JagunUserItem(this);
    user->setStatusUser(JagunMSNContact::ECSOnline);
    user->setImageUser("yoda");
    user->setNameUser("Fabio");
    user->setMessageUser("Ta nascendo :>");


    QSize s;
    s.setHeight(user->height());
    item->setSizeHint(s);
    setIndexWidget(indexFromItem(item),user);

    QListWidgetItem *item2 = new QListWidgetItem(this);
    item2->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    JagunUserItem *user2 = new JagunUserItem(this);
    user2->setStatusUser(JagunMSNContact::ECSBusy);
    user2->setImageUser("mario");
    user2->setNameUser("Adyson");
    user2->setMessageUser("Eita mah");

    QSize s2;
    s2.setHeight(user2->height());
    item2->setSizeHint(s2);
    setIndexWidget(indexFromItem(item2),user2);


    QListWidgetItem *item3 = new QListWidgetItem(this);
    item3->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    JagunUserItem *user3 = new JagunUserItem(this);
    user3->setStatusUser(JagunMSNContact::ECSOffline);
    user3->setImageUser("default");
    user3->setNameUser("Schwarzenegger");
    user3->setMessageUser("Sumi...");

    QSize s3;
    s3.setHeight(user3->height());
    item3->setSizeHint(s3);
    setIndexWidget(indexFromItem(item3),user3);*/

}

void JagunListUsers::setContactList(QList<JagunMSNContact*> list)
{
    // limpa a lista antiga
    clear();

    QListWidgetItem *item = 0;
    JagunUserItem *user = 0;

    foreach(JagunMSNContact *contact,list)
    {
        //item = new QListWidgetItem(contact->getLogin(),this);
        item = new QListWidgetItem(this);
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        user = new JagunUserItem(this);

        user->setStatusUser(contact->getStatus());
        user->setImageUser(contact->getImage());
        user->setNameUser(contact->getNickname());
        user->setMessageUser(contact->getMessage());
        user->setLoginUser(contact->getLogin() );

        QSize s;
        s.setHeight(user->height());
        item->setSizeHint(s);
        setIndexWidget(indexFromItem(item),user);
    }


}


void JagunListUsers::addNewContact(JagunMSNContact *newContact)
{
    QListWidgetItem *item = 0;
    JagunUserItem *user = 0;
    qDebug() << "JagunListUsers:: adicionando novo contato a lista";

    bool find = false;
    for(int i = 0; i < this->count(); i++)
    {
        item = this->item(i);
        user = qobject_cast<JagunUserItem*>(this->itemWidget(item));
        if ( newContact->getLogin() == user->getLoginUser()  ) {
            qDebug() << "JagunListUsers:: contato ja existente " << newContact->getLogin();
            user->setStatusUser(newContact->getStatus());
            user->setImageUser(newContact->getImage());
            user->setNameUser(newContact->getNickname());
            user->setMessageUser(newContact->getMessage());
            find = true;
            break;
        }
    }

    if (!find)
    {
        qDebug() << "JagunListUsers:: contato adicionado " << newContact->getLogin();
        item = new QListWidgetItem(this);
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        user = new JagunUserItem(this);

        user->setStatusUser(newContact->getStatus());
        user->setImageUser(newContact->getImage());
        user->setNameUser(newContact->getNickname());
        user->setMessageUser(newContact->getMessage());
        user->setLoginUser(newContact->getLogin() );

        QSize s;
        s.setHeight(user->height());
        item->setSizeHint(s);
        setIndexWidget(indexFromItem(item),user);
    }

}

void JagunListUsers::contactChangeStatus(JagunMSNContact *contact)
{
    QListWidgetItem *item = 0;
    JagunUserItem *user = 0;
    qDebug() << "JagunListUsers:: atualizando lista de contatos";

    for(int i = 0; i < this->count(); i++)
    {
        item = this->item(i);
        user = qobject_cast<JagunUserItem*>(this->itemWidget(item));
        if ( contact->getLogin() == user->getLoginUser()  ) {
            qDebug() << "JagunListUsers:: atualizando contato " << contact->getLogin();
            user->setStatusUser(contact->getStatus());
            user->setImageUser(contact->getImage());
            user->setNameUser(contact->getNickname());
            user->setMessageUser(contact->getMessage());
            return;
        }
    }
}

JagunUserItem* JagunListUsers::getItem(QString login)
{
    QListWidgetItem *item = 0;
    JagunUserItem *user = 0;
    for(int i = 0; i < this->count(); i++)
    {
        item = this->item(i);
        user = qobject_cast<JagunUserItem*>(this->itemWidget(item));
        if ( login == user->getLoginUser()  ) {
            return user;
        }
    }
    return user;
}
