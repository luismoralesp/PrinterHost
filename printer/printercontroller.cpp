#include "printercontroller.h"
#include "tickets/template.h"
#include "tickets/reciboticket.h"
#include "tickets/billticket.h"
#include "tickets/diaticket.h"
#include "printers/reciboprinter.h"
#include "printers/billprinter.h"
#include "printers/diaprinter.h"
#include <QImage>

PrinterController * PrinterController::instance = NULL;

PrinterController::PrinterController()
{
}

PrinterController * PrinterController::getInstance(){
    if(instance == NULL){
        instance = new PrinterController();
    }
    return instance;
}

QString PrinterController::print(QJsonObject data, QString printer, QString template_name){
    Template temp(Constantes::getInstancia()->getTemplate(template_name));
    //qDebug() << "data"<<temp.getText();
    temp.replace(data);

    QString template_products = temp.findInTemplate("products").replace("\n", "");
    QString title = temp.findInTemplate("title");
    QString header = temp.findInTemplate("header");
    QString footer = temp.findInTemplate("footer");
    //qDebug() << "prd: " << data["products"].toString();
    QString prd_str = data["products"].toString();
    QJsonArray array;
    if (prd_str.isEmpty()){
        array = data["products"].toArray();
    }else{
       QJsonDocument doc = QJsonDocument::fromJson(prd_str.toStdString().c_str());
       array = doc.array();
    }

    //qDebug() << "Array: " << array;

    QList<QString> products;

    for (QJsonArray::iterator it = array.begin(); it != array.end(); it++){
        QJsonValue value = *it;
        QJsonObject product = value.toObject();
        QString prod = template_products;

        QString name =  product["product__name"].toString();
        QString price = "$" + product["total_price"].toString();
        QString count = "x" + QString::number(product["count"].toInt());

        if (name.size() > 15){name = name.left(15);}
        if (price.size() > 10){price = price.left(10);}

        while (name.size() < 15){name += ".";}
        while (price.size() < 10){price = "." + price;}
        while (count.size() < 2){count = "." + count;}

        prod = prod.replace("{{name}}", name);
        prod = prod.replace("{{price}}", price);
        prod = prod.replace("{{count}}", count);

        qDebug() << "name: " << name<<" price: " << price<<" count: "<<count;
        products.append(prod);
    }
    BillTicket ticket;
    ticket.setProducts(products);
    ticket.setTitle(title);
    ticket.setHeader(header);
    ticket.setFooter(footer);

    QPixmap logo(LOGO);

    BillPrinter printe;
    printe.setLogo(logo);
    qDebug()<< "printer:" << printer << Constantes::getInstancia()->getPrinter(printer);
    printe.setPrinter(Constantes::getInstancia()->getPrinter(printer));
    printe.print(&ticket);
    return printer;
}

void PrinterController::printRecibo(QJsonObject data, int destino){
   /* Template temp(TEMPLATE_RECIBO);
    if(destino == PORTERIA){
        data.insert("recibo","Porteria");
    }else if(destino == CONTABILIDAD){
        data.insert("recibo","Contabilidad");
    }else if(destino == CLIENTE){
        data.insert("recibo","Cliente");
    }else{
        return;
    }
    temp.replace(data);
    QString pedidos = temp.findInTemplate("pedidos");
    QString recibos = temp.findInTemplate("recibo");
    QString texto = temp.findInTemplate("texto");
    QString barcode = temp.findInTemplate("barcode");

    ReciboTicket ticket;
    ticket.setPedidos(pedidos);
    ticket.setRecibo(recibos);
    ticket.setTexto(texto);
    ticket.setBarcode(barcode);

    QImage logo(LOGO);

    TicketPrinter * printer = new ReciboPrinter();
    printer->setLogo(&logo);
    printer->print(&ticket);
    delete printer;*/
}

void PrinterController::printBill(QJsonObject data){

}

void PrinterController::printDia(QJsonObject data){
    /*Template temp(TEMPLATE_DIA);
    temp.replace(data);
    QString dia = temp.findInTemplate("dia");
    temp.replace("texto","dia",dia);

    QString texto = temp.findInTemplate("texto");
    int numero = data["dia"].toArray().count();

    DiaTicket ticket;
    ticket.setTexto(texto);
    ticket.setNumero(numero);

    QImage logo(LOGO);

    TicketPrinter * printer = new DiaPrinter();
    printer->setLogo(&logo);
    printer->print(&ticket);
    delete printer;*/
}
