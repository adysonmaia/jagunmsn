#include <QtCore/QCoreApplication>

#include "jagunmsnserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    JagunMSNServer *server;
    server = new JagunMSNServer(9999);

    return a.exec();
}
