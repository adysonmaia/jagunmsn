#ifndef JAGUNCHATLISTUSERS_H
#define JAGUNCHATLISTUSERS_H

#include <QListWidget>
#include "jagunmsncontact.h"
#include "jagunchatuseritem.h"

/**
 * Controla a lista de usuarios no chat
 */
class JagunChatListUsers : public QListWidget
{
public:
    /**
     * Construtor
     */
    JagunChatListUsers(QWidget *parent = 0);
    /**
     * Adiciona um usuario a conversa
     */
    void addGuest(QString login, QString name,QString imageName, QString message, JagunMSNContact::ECStatus status);

    bool containsGuest(QString login);
    void setStateGuest(QString login, QString name,QString imageName, QString message, JagunMSNContact::ECStatus status);

    JagunChatUserItem* getItem(QString login);
};

#endif // JAGUNCHATLISTUSERS_H
