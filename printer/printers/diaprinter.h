#ifndef DIAPRINTER_H
#define DIAPRINTER_H
#include "ticketprinter.h"
#include "printer/tickets/diaticket.h"

class DiaPrinter: public TicketPrinter
{
public:
    DiaPrinter();
    void print(Ticket * ticket);
};

#endif // DIAPRINTER_H
