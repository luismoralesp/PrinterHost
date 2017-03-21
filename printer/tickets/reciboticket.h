#ifndef RECIBOTICKET_H
#define RECIBOTICKET_H

#include "ticket.h"

class ReciboTicket: public Ticket
{
public:
    ReciboTicket();

    void setPedidos(QString pedidos);
    QString getPedidos();

    void setRecibo(QString recibo);
    QString getRecibo();

    void setBarcode(QString barcode);
    QString getBarcode();

private:
    QString pedidos;
    QString recibo;
    QString barcode;
};

#endif // RECIBOTICKET_H
