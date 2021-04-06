#include "jagunmsncontact.h"

JagunMSNContact::JagunMSNContact(const QString& loginValue)
                : login(loginValue) , nickname(loginValue)
{
    status  = ECSOffline;
    blocked = false;
}

JagunMSNContact::JagunMSNContact(const QString& loginValue, const QString& nick, const QString& img, const QString& msg,
                                 const QString& emailValue, ECStatus statusValue, bool blockedValue)
                : login(loginValue), nickname(nick), image(img), message(msg),
                  email(emailValue), status(statusValue), blocked(blockedValue)
{
}
