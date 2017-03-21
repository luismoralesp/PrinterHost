#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H
#include <QHash>

class HttpResponse
{
public:
    HttpResponse(QString response, QString status);
    QString toString();
    void addHeader(QString key, QString value);
private:
    QHash<QString, QString> headers;
    QString status;
    QString body;
};

#endif // HTTPRESPONSE_H
