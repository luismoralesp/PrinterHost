#include "reciboticket.h"

ReciboTicket::ReciboTicket()
{
}

void ReciboTicket::setPedidos(QString pedidos){
    this->pedidos = pedidos;
}

QString ReciboTicket::getPedidos(){
    return this->pedidos;
}

void ReciboTicket::setRecibo(QString recibo){
    this->recibo = recibo;
}

QString ReciboTicket::getRecibo(){
    return this->recibo;
}

void ReciboTicket::setBarcode(QString barcode){
    this->barcode = barcode;
}

QString ReciboTicket::getBarcode(){
    return this->barcode;
}
