#ifndef SERVERCONECTOR_H
#define SERVERCONECTOR_H
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QHash>
#include <QJsonDocument>
#include <QTime>
#include <QCoreApplication>

class ServerConector: public QObject
{
    Q_OBJECT
private:
    ServerConector();
    QNetworkAccessManager * conector;
    static ServerConector * instance;
    bool waiting;
    QJsonDocument *data;

    void delay(int milis);

private slots:
    void response(QNetworkReply *reply);

public:
    static ServerConector * getInstance();
    void request(QHash<QString,QString> &data, QString url, bool post);
    void waitFor();
    QJsonDocument * getData();

};
#endif // SERVERCONECTOR_H
