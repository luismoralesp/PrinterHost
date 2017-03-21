#include "billprinter.h"
#include <QDebug>
BillPrinter::BillPrinter()
{

}

void BillPrinter::print(Ticket *ticket){
    BillTicket * t = (BillTicket *) ticket;
    QList<QString> products =  t->getProducts();
    printer.setPageSizeMM(QSizeF(77.7, 130 + 3.9*products.size()));

    painter.begin(&printer);
    painter.setBrush(Qt::NoBrush);
    painter.setPen(QColor(0,0,0));
    painter.scale(0.70f,0.70f);

    printSection(t->getTitle(), font_t, Qt::AlignLeft|Qt::AlignTop);
    printSection(t->getHeader(), font_p, Qt::AlignLeft|Qt::AlignTop);
    for (QList<QString>::Iterator it = products.begin(); it != products.end(); it++){
        QString product = *it;
        qDebug() << "P:" << product;
        printSection(product, font_p, Qt::AlignLeft|Qt::AlignTop);
    }
    printSection(t->getFooter(), font_p, Qt::AlignLeft|Qt::AlignTop);

    /*painter.setFont(font_t);
    QStringList titles = t->getTitle().split("\n");

    for (QStringList::Iterator it = titles.begin(); it != titles.end(); it++){
        QString title = *it;
        painter.drawText(20, 25, 375, 850, Qt::AlignLeft|Qt::AlignTop, title);
    }

    painter.setFont(font_p);
    painter.drawText(25, 125, 375, 700, Qt::AlignLeft|Qt::AlignTop, t->getHeader());

    painter.setFont(font_p);
    int i = 0;
    for (QList<QString>::Iterator it = products.begin(); it != products.end(); it++){
        QString product = *it;
        painter.drawText(25, 220 + i*20, 375, 700, Qt::AlignLeft|Qt::AlignTop, product);
        i++;
    }
    painter.setFont(font_p);
    painter.drawText(25, 220 + products.size()*20, 375, 700, Qt::AlignLeft|Qt::AlignTop, t->getFooter());
*/

    painter.end();
}
