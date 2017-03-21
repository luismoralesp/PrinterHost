#include <QString>
#ifndef TICKET_H
#define TICKET_H

class Ticket {
    public:
        Ticket();

        void setTitle(QString title);
        QString getTitle();

        void setHeader(QString header);
        QString getHeader();

        void setFooter(QString footer);
        QString getFooter();

    private:
        QString title;
        QString header;
        QString footer;
};

#endif // TICKET_H
