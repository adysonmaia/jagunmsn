#include <QtCore/QCoreApplication>
#include "jagunket.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //JagunKET socket(0);
    //socket.connectToHost(QHostAddress::LocalHost,9999);
    return a.exec();
}
