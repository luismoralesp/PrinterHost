#include "httprequest.h"
#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>


HttpRequest::HttpRequest(QString http_string)
{
    QString exp = "(\\w|\\-)+: (\\w|\\,| |\\=|-|\\.|\\:|\\/|\\(|\\)|\\*|\\;)+";
    QRegularExpression regexp(exp);
    QRegularExpressionMatchIterator it = regexp.globalMatch(http_string);
    while (it.hasNext()) {
        QRegularExpressionMatch match = it.next();
        QString word = match.captured(0);
        QStringList words = word.split(": ");
        this->headers[words[0]] = words[1];
    }
    QString exp_meth = "^(GET|POST|PUT|DELETE|OPTIONS)";
    QRegularExpression meth(exp_meth);
    QRegularExpressionMatch meth_maatch = meth.match(http_string);
    this->method = meth_maatch.captured(0);
    http_string.replace(QRegularExpression("(\\w|\\-)+: (\\w|\\,| |\\=|-|\\.|\\:|\\/|\\(|\\)|\\*|\\;)+\\r\\n"), "");
    http_string.replace(QRegularExpression("^(GET|POST|PUT|DELETE|OPTIONS) (\\/|\\w|\\.)+ HTTP/(\\d|\\.)+\\r\\n"), "");
    http_string.replace(QRegularExpression("^\\r\\n"), "");
    qDebug() << "replaced" << http_string;
    this->body = http_string.left(this->headers["Content-Length"].toInt());
    qDebug() << "body" << this->body;
}

QString HttpRequest::getHeader(QString key)
{
    return this->headers[key];
}

QString HttpRequest::getPOST(QString key, QString def)
{
    //not implememented
}

QString HttpRequest::getGET(QString key, QString def)
{
    //not implemented
}

QString HttpRequest::getBody(){
    return this->body;
}

QString HttpRequest::getMethod(){
    return this->method;
}
