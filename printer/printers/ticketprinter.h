#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include "printer/tickets/ticket.h"

#ifndef TICKETPRINTER_H
#define TICKETPRINTER_H

class TicketPrinter{
    public:
        virtual void print(Ticket * ticket)=0;
        void setLogo(QPixmap logo);

        void setPrinter(QString printername);
        void printSection(QString section, QFont font, int flags);
        void printLogo();

    private:
        int line;
        int size;
    protected:
        TicketPrinter();
        QPrinter printer;
        QPixmap logo;
        QPainter painter;
        QFont font_t;
        QFont font_p;
        QFont font_r;
        int margin;
        int interlineado;
};

#endif // TICKETPRINTER_H
