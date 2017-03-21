#include "httpserver.h"
#include <iostream>
#include <QDebug>
using namespace std;

HttpServer::HttpServer(QObject* parent): QObject(parent)
{
  connect(&server, SIGNAL(newConnection()),
    this, SLOT(acceptConnection()));
}

HttpServer::~HttpServer()
{

}

void HttpServer::start(int port)
{
    if(server.listen(QHostAddress::Any, port)){
        qDebug() << "Error" << server.errorString();
    }
}

void HttpServer::stop()
{
    server.close();
}

void HttpServer::acceptConnection()
{
  client = server.nextPendingConnection();

  connect(client, SIGNAL(readyRead()),
    this, SLOT(startRead()));
}

void HttpServer::startRead()
{
    QString buffer_string = "";
    int times = client->bytesAvailable()/1024;
    //qDebug() << "nums:" << client->bytesAvailable();
    for (int i = 0; i < times; i++){
        char buffer[1024] = {0};
        client->read(buffer, 1024);
        buffer_string += QString(buffer);
    }
    int mod = client->bytesAvailable()%1024;
    if (mod > 0){
        char buffer[mod] = {0};
        client->read(buffer, mod);
        buffer_string += QString(buffer);
    }
    if (buffer_string.length() > 0){
        //qDebug() << "FF: " << buffer_string;
        HttpResponse response = this->response(HttpRequest(buffer_string));

        response.addHeader("Access-Control-Allow-Origin", this->allow);
        QString h = response.toString();
        //qDebug() << "response==============";
        //qDebug() << h;
        client->write(h.toStdString().c_str());
    }
    client->close();
    //qDebug()<< "close";
}

QString HttpServer::getAllow() const
{
    return allow;
}

void HttpServer::setAllow(const QString &allow)
{
    this->allow = allow;
}
