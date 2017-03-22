#include "ticketprinter.h"
#include "qprinterinfo.h"
#include "qdebug.h"

TicketPrinter::TicketPrinter():font_t(QFont("courier new", 12, QFont::Bold)), font_p(QFont("courier new", 10, QFont::Bold)),font_r(QFont("courier new", 16, QFont::Bold)){
    font_r.setBold(true);
    margin = 5;
    interlineado = 8;
    line = 0;
    qDebug() <<"init";
    //qDebug() << QPrinterInfo::availablePrinterNames();
    //printer.setPrinterName("EPSON TM-T20 Receipt");
    //Microsoft XPS Document Writer
    //EPSON82522B (L355 Series)  -- de tiquetes
    //Microsoft XPS Document Writer -- PC windows
    //EPSON841C52 (L355 Series)   -- normal
}

void TicketPrinter::setLogo(QPixmap logo){
    this->logo = logo;
}

void TicketPrinter::setPrinter(QString printername){
    this->printer.setPrinterName(printername);
}

void TicketPrinter::printSection(QString section, QFont font, int flags){
    QStringList titles = section.split("\n");
    painter.setFont(font);
    for (QStringList::Iterator it = titles.begin(); it != titles.end(); it++){
        QString title = *it;
        painter.drawText(this->margin, this->line + this->interlineado, 425 - this->margin, 850, flags, title);
        this->line += font.pointSize() + this->interlineado;
        qDebug() << "line" << this->line<<" "<<title;
    }

}

void TicketPrinter::printLogo(){
    painter.drawPixmap(440/2 - 50, 0, 100, 100, logo);
    this->line += 120;
}
