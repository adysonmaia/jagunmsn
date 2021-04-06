#include <QtCore/QCoreApplication>
#include "jagundb.h"
#include <QtSql>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    JagunDb DB;
    DB.createNewConnection();
    QString login = "Wario";
    QString mail = "Wario@mushroomland.com";
    QString pass = "Wario";
    QList<JagunMSNContact *> list;
    QString login2 = "mario";

    JagunMSNContact *contact = new  JagunMSNContact();



    DB.addContact(login,login2,"TO C SONO");
    contact = DB.getData(login);
    list = DB.getList(login);

    for ( QList<JagunMSNContact*>::const_iterator it = list.begin(); it != list.end(); ++it )
    {
        QString login1 = (*it)->getLogin();
        QString nick  = (*it)->getNickname();
        QString img   = (*it)->getImage();
        QString msg   = (*it)->getMessage();
        QString email = (*it)->getEmail();
        int status    = (int) (*it)->getStatus();
        qDebug() << login1;
        qDebug() << nick;
        qDebug() << img;
        qDebug() << status;

    }

        QString login3 = contact->getLogin();
        QString nick2  = contact->getNickname();
        QString img2   = contact->getImage();
        QString msg2   = contact->getMessage();
        QString email2 = contact->getEmail();
        int status2 =  contact->getStatus();
        qDebug() << login3;
        qDebug() << nick2;
        qDebug() << img2;
        qDebug() << status2;

    QList< QPair <QString,QString > > listteste;

    listteste = DB.getUnconCont(login2);
    qDebug() <<listteste;



    return a.exec();
}
