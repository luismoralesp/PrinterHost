#ifndef PRINTERCONTROLLER_H
#define PRINTERCONTROLLER_H
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include "constantes.h"

class PrinterController
{
public:
    static PrinterController * getInstance();
    QString print(QJsonObject data, QString printer, QString template_name);
private:
    PrinterController();
    static PrinterController * instance;
    void printRecibo(QJsonObject data, int destino);
    void printBill(QJsonObject data);
    void printDia(QJsonObject data);
};

#endif // PRINTERCONTROLLER_H
