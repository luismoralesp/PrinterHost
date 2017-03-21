#ifndef DIATICKET_H
#define DIATICKET_H
#include "ticket.h"

class DiaTicket: public Ticket
{
public:
    DiaTicket();
    void setNumero(int numero);
    int getNumero();
private:
    int numero;
};

#endif // DIATICKET_H
