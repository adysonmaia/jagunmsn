#ifndef JAGUNCHATUSERITEM_H
#define JAGUNCHATUSERITEM_H

#include "ui_jagunchatuseritem.h"
#include "jagunmsncontact.h"
/**
 * Item de visualizacao com informacao de nome e imagem do usuario no chat
 */
class JagunChatUserItem : public QWidget, private Ui::JagunChatUserItem {
    Q_OBJECT
    Q_DISABLE_COPY(JagunChatUserItem)
public:
    explicit JagunChatUserItem(QWidget *parent = 0);
    /**
     * muda a cor de fundo indicado o status do usuario
     */
    void setStatusUser(JagunMSNContact::ECStatus status);
    /**
     * muda a imagem de exibicao do usuario
     */
    void setImageUser(QString name);
    /**
     * get e set do nome de usuario
     */
    void setNameUser(QString name);
    QString getNameUser();

    void setLoginUser(QString login);
    QString getLoginUser();

    void setMessageUser(QString message);
    QString getMessageUser();
private:
    QString login;
    JagunMSNContact::ECStatus status;
    QString message;
protected:
    virtual void changeEvent(QEvent *e);
};

#endif // JAGUNCHATUSERITEM_H
