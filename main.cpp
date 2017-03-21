#include <QApplication>
#include "pluginhost/printerhost.h"
#include "http/printerserver.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PrinterServer server;
    MainWindow win;
    win.init();
    server.start(8888);
    return a.exec();
}
