#ifndef BILLPRINTER_H
#define BILLPRINTER_H
#include "ticketprinter.h"
#include "printer/tickets/billticket.h"

class BillPrinter: public TicketPrinter
{
public:
    BillPrinter();
    void print(Ticket * ticket);
};

#endif // BILLPRINTER_H
