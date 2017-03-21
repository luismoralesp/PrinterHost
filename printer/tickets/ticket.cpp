#include "ticket.h"

Ticket::Ticket()
{
}

void Ticket::setTitle(QString title){
    this->title = title;
}

QString Ticket::getTitle(){
    return this->title;
}


void Ticket::setHeader(QString header){
    this->header = header;
}

QString Ticket::getHeader(){
    return this->header;
}

void Ticket::setFooter(QString footer){
    this->footer = footer;
}

QString Ticket::getFooter(){
    return this->footer;
}
