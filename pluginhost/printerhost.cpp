#include "printerhost.h"
#include <QJsonDocument>
#include <QJsonObject>
#include "printer/ticketcontroller.h"


PrinterHost::PrinterHost()
{
}

string PrinterHost::onMessage(string msg){
    log(msg);
    QJsonDocument doc = QJsonDocument::fromJson(msg.c_str());
    TicketController * controller = TicketController::getInstance();

    QString str = controller->printTicket(doc);
    log(str.toStdString());

    delete controller;
    return "1";
}
