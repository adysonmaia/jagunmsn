#ifndef JAGUNLISTUSERS_H
#define JAGUNLISTUSERS_H

#include <QListWidget>
#include <QDebug>
#include "jagunmsncontact.h"
#include "jagunuseritem.h"

class JagunListUsers : public QListWidget
{
    Q_OBJECT
public:
    JagunListUsers(QWidget *parent = 0);
    JagunUserItem* getItem(QString login);
public slots:
    /**
     * lista de contatos para visualizacao
     */
    void setContactList(QList<JagunMSNContact*> list);
    /**
     * adiciona um novo contato a lista
     */
    void addNewContact(JagunMSNContact *newContact);
    /**
     * muda o estatus de um contato
     */
    void contactChangeStatus(JagunMSNContact *newContact);
};

#endif // JAGUNLISTUSERS_H
