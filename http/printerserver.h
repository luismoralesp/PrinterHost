#ifndef PRINTERSERVER_H
#define PRINTERSERVER_H
#include "httpserver.h"

class PrinterServer: public HttpServer
{
public:
    PrinterServer();
    HttpResponse response(HttpRequest request);
};

#endif // PRINTERSERVER_H
