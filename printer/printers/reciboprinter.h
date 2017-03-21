#ifndef RECIBOPRINTER_H
#define RECIBOPRINTER_H
#include "ticketprinter.h"
#include "printer/tickets/reciboticket.h"

class ReciboPrinter: public TicketPrinter
{
public:
    ReciboPrinter();
    void print(Ticket * ticket);
};

#endif // RECIBOPRINTER_H
