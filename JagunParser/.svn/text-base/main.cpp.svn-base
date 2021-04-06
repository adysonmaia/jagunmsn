#include <QtCore/QCoreApplication>

#include "teste.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDateTime date = QDateTime::currentDateTime();
    QList<JagunMSNContact*> list;

    JagunMSNContact *contact = new JagunMSNContact("adyson","Adyson","default","cappim","adyson.maia@gmail.com",JagunMSNContact::ECSOnline,false);
    list << contact;
    contact = new JagunMSNContact("ghost_amm","AdsArts","default","cappim","adyson.maia@yahoo.com",JagunMSNContact::ECSOffline,true);
    list << contact;

    QStringList sendToo;
//    sendToo << "ghost_amm" << "adsarts";
    qDebug() << sendToo.size();

    Teste parser;
    //parser.messageNewUser("adyson.maia","123456", "adyson.maia@gmail.com");
    //parser.messageUserCreated("adyson.maia",date);
    //parser.messageUserNotCreated("Ja existe um usuario com este login");
    //parser.messageLoginUser("adyson.maia","123456");
    //parser.messageLogOn("adyson.maia","adyson","Capim foreviss","burro",1);
    //parser.messageLoginUserError("senha errada");
    //parser.messageAddContact("adyson","ola, como vai?");
    //parser.messageContactList(list);
    parser.messageChangeStatus("adyson","Capim foreviss","burro",1,sendToo);

    return a.exec();
}
