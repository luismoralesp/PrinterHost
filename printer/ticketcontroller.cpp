#include "ticketcontroller.h"

TicketController * TicketController::instance = NULL;

TicketController::TicketController()
{
}

TicketController * TicketController::getInstance(){
    if(instance == NULL){
        instance = new TicketController();
    }
    return instance;
}

QString TicketController::printTicket(QJsonDocument json){
    QJsonObject object = json.object();
    qDebug() << json;
    QString template_name = object.value("template").toString();
    QString printer = object.value("printer").toString();
    QJsonObject data_obj = object.value("data").toObject();
    QString service_name = object.value("service").toString();
    qDebug()<<"prt: "<<template_name;
    QStringList keys = data_obj.keys();
    QHash<QString, QString> hash;
    for(QStringList::iterator it = keys.begin(); it != keys.end(); it++){
        QString key = *it;
        QJsonValue value = data_obj.value(key);
        hash.insert(key, value.toString());
    }

    QString service = Constantes::getInstancia()->getService(service_name, hash);


    QJsonObject ticket_data = this->getTicketData(service, hash);

    PrinterController * pc = PrinterController::getInstance();

    QString pr = pc->print(ticket_data, printer, template_name);
    delete pc;
    QJsonDocument d(ticket_data);
    return "printed! " + QString(d.toJson()) + " " + pr;
}



void TicketController::printRecibo(QString venta, int destino){
    /*QJsonObject data = this->getVentaData(venta);
    if(destino == PORTERIA && data.keys().contains("impreso") && data.value("impreso").toBool()){
        return;
    }

    PrinterController * printer = PrinterController::getInstance();

    printer->print(data.value("venta").toObject(), RECIBO_PRINTER, destino);*/
}

void TicketController::printPedido(QString venta){
    /*QJsonObject data = this->getVentaData(venta);
    PrinterController * printer = PrinterController::getInstance();
    printer->print(data,PEDIDO_PRINTER);*/
}

void TicketController::printDia(QString fecha){
   /* QJsonObject data = this->getDiaData(fecha);
    PrinterController * printer = PrinterController::getInstance();*
    printer->print(data,DIA_PRINTER);*/
}

QJsonObject TicketController::getTicketData(QString service, QHash<QString, QString> data){
    if(this->login()){
        ServerConector * conector = ServerConector::getInstance();
        QString url = Constantes::getInstancia()->getServerURL();
        qDebug()<<"URL: "<<url+service;
        conector->request(data, url + service, false);
        conector->waitFor();
        QJsonDocument * doc = conector->getData();
        if(doc != NULL && doc->isObject()){
            return doc->object();
        }
    }
    return QJsonObject();
}

QJsonObject TicketController::getDiaData(QString fecha){
    if(this->login()){
        ServerConector * conector = ServerConector::getInstance();
        QHash<QString,QString> t;
        t.insert("dia",fecha);
        QString url = SERVER_URL;
        conector->request(t,url + "venta/json_dia/",true);
        conector->waitFor();
        QJsonDocument * doc = conector->getData();
        if(doc !=NULL && doc->isObject()){
            return doc->object();
        }
    }
    return QJsonObject();
}

bool TicketController::login(){
    ServerConector * conector = ServerConector::getInstance();
    QHash<QString,QString> t;
    Constantes * c = Constantes::getInstancia();
    qDebug() <<c->getLogin("username_value")<<"?";
    t.insert(c->getLogin("username_name"), c->getLogin("username_value"));
    t.insert(c->getLogin("password_name"), c->getLogin("password_value"));
    t.insert(c->getTokenName(), this->getToken());
    QString url = c->getServerURL();
    conector->request(t, url + c->getLogin("service"),true);
    conector->waitFor();
    if(conector->getData() != NULL){
        return true;
    }
    return false;
}

QString TicketController::getToken(){
    ServerConector * conector = ServerConector::getInstance();
    QHash<QString,QString> t;
    QString url = Constantes::getInstancia()->getServerURL();
    QString token_service = Constantes::getInstancia()->getTokenService();
    QString token_key = Constantes::getInstancia()->getTokenKey();
    conector->request(t, url + token_service, false);
    conector->waitFor();
    QJsonObject token = conector->getData()->object();

    return token.value(token_key).toString();
}
