#ifndef JAGUNUSERITEM_H
#define JAGUNUSERITEM_H

#include "ui_jagunuseritem.h"
#include "jagunmsncontact.h"
/**
 * item de visualizacao da lista de usuarios
 */
class JagunUserItem : public QWidget, private Ui::JagunUserItem
{
    Q_OBJECT
    Q_DISABLE_COPY(JagunUserItem)
public:
    /**
     * Construtor
     */
    explicit JagunUserItem(QWidget *parent = 0);
    /**
     * muda o status do usuario
     */
    void setStatusUser(JagunMSNContact::ECStatus status);
    JagunMSNContact::ECStatus getStatusUser();
    /**
     * get e set imagem de exibicao do usuario
     */
    void setImageUser(QString name);
    QString getImageUser();
    /**
     * get e set do nome de usuario
     */
    void setNameUser(QString name);
    QString getNameUser();
     /**
     * muda a mensagem do usuario
     */
    void setMessageUser(QString message);
    QString getMessageUser();
    /**
     * retorna o login do usuario
     */
    QString getLoginUser();
    /**
     * muda o login do usuario
     */
    void setLoginUser(QString newLogin);
private:
    /**
     * nome da imagem do usuario
     */
    QString imgName;
    /**
     * login do usuario
     */
    QString login;
    JagunMSNContact::ECStatus status;
};

#endif // JAGUNUSERITEM_H
