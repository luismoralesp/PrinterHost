#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <QtNetwork>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "httpresponse.h"
#include "httprequest.h"

class HttpServer: public QObject
{
    Q_OBJECT
    public:
      HttpServer(QObject * parent = 0);
      ~HttpServer();
      void start(int port);
      void stop();
      virtual HttpResponse response(HttpRequest request) = 0;
      QString getAllow() const;
      void setAllow(const QString &allow);

public slots:
      void acceptConnection();
      void startRead();
    private:
      QTcpServer server;
      QTcpSocket * client;
      QString allow;
};

#endif // HTTPSERVER_H
