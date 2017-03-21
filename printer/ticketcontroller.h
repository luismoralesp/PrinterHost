#ifndef TICKETCONTROLLER_H
#define TICKETCONTROLLER_H

#include "server/serverconector.h"
#include "printercontroller.h"

class TicketController
{
private:
    TicketController();
    static TicketController * instance;

    void printRecibo(QString venta, int destino);
    void printPedido(QString venta);
    void printDia(QString fecha);

    QJsonObject getTicketData(QString service, QHash<QString, QString> data);
    QJsonObject getDiaData(QString fecha);
    QString getToken();
    bool login();

public:
    static TicketController * getInstance();
    QString printTicket(QJsonDocument json);

};

#endif // TICKETCONTROLLER_H
