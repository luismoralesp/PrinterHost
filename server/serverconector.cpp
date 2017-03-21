#include "serverconector.h"

ServerConector * ServerConector::instance = NULL;

ServerConector::ServerConector()
{
    this->conector = new QNetworkAccessManager(this);
    connect(this->conector,SIGNAL(finished(QNetworkReply*)),this,SLOT(response(QNetworkReply*)));
    this->waiting = false;
    this->data = NULL;
}

ServerConector * ServerConector::getInstance(){
    if(instance == NULL){
        instance = new ServerConector();
    }
    return instance;
}

QJsonDocument *ServerConector::getData(){
    return this->data;
}

void ServerConector::request(QHash<QString, QString> &data, QString url,bool post){
    QHashIterator <QString,QString> it(data);
    QString d = "";
    while (it.hasNext()) {
        it.next();
        d += it.key() + "=" + it.value();
        if(it.hasNext()){
            d +="&";
        }
    }
    if(post){
        QByteArray postData;
        postData.append(d);
        this->conector->post(QNetworkRequest(QUrl(url)),postData);
    }else{
        url += "?"+d;
        this->conector->get(QNetworkRequest(QUrl(url)));
    }
    this->waiting = true;
    this->data = NULL;
}

void ServerConector::response(QNetworkReply *reply){
    if(reply->error() == QNetworkReply::NoError){
        QString res = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8());
        this->data = new QJsonDocument(doc);
    }else{
        this->data = NULL;
        qDebug() << reply->errorString();
    }
    this->waiting = false;
}


void ServerConector::delay(int milis){
    QTime dieTime = QTime::currentTime().addMSecs(milis);
    while (QTime::currentTime() < dieTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}


void ServerConector::waitFor(){
    while (this->waiting) {
        delay(50);
    }
}
