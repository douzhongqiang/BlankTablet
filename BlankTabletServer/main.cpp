#include <QCoreApplication>
#include "BlankTabletTcpServer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    BlankTabletTcpServer* pBlankTabletTcpServer = new BlankTabletTcpServer;

    return a.exec();
}
