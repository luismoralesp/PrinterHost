#include "billticket.h"

BillTicket::BillTicket()
{
}

void BillTicket::setProducts(QList<QString> products){
    this->products = products;
}

QList<QString> BillTicket::getProducts(){
    return products;
}

