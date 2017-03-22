#include "printerserver.h"
#include <QJsonDocument>
#include <QJsonObject>
#include "printer/ticketcontroller.h"
#include "printer/constantes.h"
#include <QDebug>

PrinterServer::PrinterServer()
{
    QString allow = Constantes::getInstancia()->getAllow();
    this->setAllow(allow);
}

HttpResponse PrinterServer::response(HttpRequest request)
{
    QJsonDocument doc = QJsonDocument::fromJson(request.getBody().toStdString().c_str());
    TicketController * controller = TicketController::getInstance();

    QString str = "";
    if (request.getMethod() == "POST"){
        str = controller->printTicket(doc);
    }
    qDebug() << request.getMethod();
    //QJsonObject obj = doc.object();
    //QString var = obj["hola"].toString();
    return HttpResponse(str, "200 Ok");
}
