#ifndef BILLTICKET_H
#define BILLTICKET_H
#include "ticket.h"
#include "qlist.h"

class BillTicket: public Ticket
{
public:
    BillTicket();

    void setProducts(QList<QString> products);
    QList<QString> getProducts();


private:
    QList<QString> products;
};

#endif // BILLTICKET_H
