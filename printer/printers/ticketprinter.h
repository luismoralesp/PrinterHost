#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include "printer/tickets/ticket.h"

#ifndef TICKETPRINTER_H
#define TICKETPRINTER_H

class TicketPrinter{
    public:
        virtual void print(Ticket * ticket)=0;
        void setLogo(QImage * logo);

        void setPrinter(QString printername);
        void printSection(QString section, QFont font, int flags);

    private:
        int line;
        int size;
    protected:
        TicketPrinter();
        QPrinter printer;
        QImage * logo;
        QPainter painter;
        QFont font_t;
        QFont font_p;
        QFont font_r;
};

#endif // TICKETPRINTER_H
