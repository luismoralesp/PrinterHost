#include "reciboprinter.h"
#include "printer/barcode/code128item.h"
#include <QDebug>

ReciboPrinter::ReciboPrinter()
{
    printer.setPageSizeMM(QSizeF(77.7, 210));
}

void ReciboPrinter::print(Ticket *ticket){
   /* ReciboTicket * t = (ReciboTicket *) ticket;
    painter.begin(&printer);
    painter.setBrush(Qt::NoBrush);
    painter.setPen(QColor(0,0,0));
    painter.scale(0.70f,0.70f);
    painter.setFont(font_t);
    painter.drawText(20, 125, 375, 850, Qt::AlignLeft|Qt::AlignTop, t->getTexto());
    painter.setFont(font_p);
    painter.drawText(25, 145, 375, 700, Qt::AlignLeft|Qt::AlignTop, t->getPedidos());
    painter.setFont(font_r);
    painter.drawText(20, 800, 375, 700, Qt::AlignLeft|Qt::AlignTop, t->getRecibo());
    if (logo != NULL){
        painter.drawImage(QPoint(90, 20), *logo);
    }
    Code128Item * m_Barcode = new Code128Item();
    m_Barcode->setWidth(330);
    m_Barcode->setHeight(100);
    m_Barcode->setPos(25, 1000);
    m_Barcode->setText(t->getBarcode());
    m_Barcode->paint(&painter,NULL,NULL);
    painter.end();
    */
}
