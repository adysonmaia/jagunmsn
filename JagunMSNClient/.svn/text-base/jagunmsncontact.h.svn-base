#ifndef JAGUNMSNCONTACT_H
#define JAGUNMSNCONTACT_H

#include <QString>
#include <QObject>

/**
 * Classe responsavel por manter os dados de um contato
 */
class JagunMSNContact
{

public:
    /**
     * Status quem um contato pode estar
     */
    enum ECStatus {
        ECSOffline    = 0,  // contato offline
        ECSOnline    = 1,  // contato online
        ECSBusy      = 2,  // contato ocupado
        ECSAway      = 3,  // contato ausente
        ECSInvisible = 4, // contato invisivel
    };

    inline JagunMSNContact() {}
    JagunMSNContact(const QString& login);
    JagunMSNContact(const QString& login, const QString& nickname, const QString& image,
                    const QString& message, const QString& email, ECStatus status, bool blocked);

    inline QString getLogin() const {return login;}
    inline void setLogin(const QString& newLogin) {login=newLogin;}

    inline QString getNickname() const {return nickname;}
    inline void setNickname(const QString& newNick) {nickname=newNick;}

    inline QString getImage() const {return image;}
    inline void setImage(const QString newImage) {image=newImage;}

    inline QString getMessage() const {return message;}
    inline void setMessage(const QString& newMessage) {message=newMessage;}

    inline QString getEmail() const {return email;}
    inline void setEmail(const QString& newEmail) {email=newEmail;}

    inline ECStatus getStatus() const {return status;}
    inline void setStatus(ECStatus newStatus) {status=newStatus;}

    inline ECStatus getLastStatus() const {return laststatus;}
    inline void setLastStatus(ECStatus newLastStatus) {laststatus=newLastStatus;}

    /**
     * retorna se o contato esta bloqueado ou nao
     */
    inline bool isBlocked() const {return blocked;}
    /**
     * bloqueia um usuario (block=true) ou desbloqueia (block=false)
     */
    inline void setBlocked(bool block) {blocked=block;}
private:
    QString login;
    QString nickname;
    QString image;
    QString message;
    QString email;
    ECStatus status;
    ECStatus laststatus;
    bool blocked;
};

#endif // JAGUNMSNCONTACT_H
