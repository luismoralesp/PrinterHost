#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H
#include <QHash>

class HttpRequest
{
public:
    HttpRequest(QString http_string);
    QString getHeader(QString key);
    QString getPOST(QString key, QString def);
    QString getGET(QString key, QString def);
    QString getBody();
    QString getMethod();
private:
    QHash<QString, QString> headers;
    QString method;
    QString body;
};

#endif // HTTPREQUEST_H
