#include "httpresponse.h"

HttpResponse::HttpResponse(QString response, QString status)
{

    this->status = "HTTP/1.1 " + status;
    this->headers["Accept"] = "application/json, text/plain, */*";
    this->headers["User-Agent"] = "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.116 Safari/537.36";
    this->headers["Content-Length"] = QString("%1").arg(response.length());
    this->headers["Connection"] = "keep-alive";
    this->headers["Content-Type"] = "text/html; charset=utf-8";
    /**
      * Server
      */
    this->headers["Server"] = "PrinterHost/0.1 QtC++/5.4";
    /**
      * Access
      */
    this->headers["Access-Control-Allow-Origin"] = "";
    this->headers["Access-Control-Allow-Credentials"] = "true";
    this->headers["Access-Control-Allow-Headers"] = "accept, content-type";
    this->headers["Access-Control-Max-Age"] = "1728000";
    this->headers["Vary"] += "Accept-Encoding, Origin";
    this->headers["Access-Control-Allow-Methods"] = "POST, GET, OPTIONS";

    this->body = response;
}

QString HttpResponse::toString(){
    QString headers = "";
    headers += this->status + "\n";
    QList<QString> keys = this->headers.keys();
    for(QList<QString>::Iterator it = keys.begin(); it != keys.end(); it ++){
        QString key = *it;
        QString value = this->headers[key];
        headers += key + ": " + value + "\n";
    }
    headers += "\n";
    headers += this->body;
    return headers;
}

void HttpResponse::addHeader(QString key, QString value){
    this->headers[key] = value;
}
