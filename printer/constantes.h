#ifndef CONSTANTES_H
#define CONSTANTES_H

#define PEDIDO_PRINTER 1
#define RECIBO_PRINTER 2
#define DIA_PRINTER 3

#define PORTERIA 1
#define CONTABILIDAD 2
#define CLIENTE 3

#define LOGO "C:\\Program Files\\ScriptQuo\\PrinterHost\\logo.png"
#define TEMPLATE_RECIBO "C:\\Program Files\\ScriptQuo\\PrinterHost\\template2.txt"
#define TEMPLATE_PEDIDO "C:\\Program Files\\ScriptQuo\\PrinterHost\\template3.txt"
#define TEMPLATE_DIA "C:\\Program Files\\ScriptQuo\\PrinterHost\\template4.txt"
#define PRINTERS "C:\\Program Files\\ScriptQuo\\PrinterHost\\printers.txt"
#define DEFAULT_DIR "C:\\Program Files\\ScriptQuo\\PrinterHost\\"

#define CONFIG_FILE "C:\\Program Files\\ScriptQuo\\PrinterHost\\config.dat"
#define SERVER_URL "http://192.168.42.129:8000/"
#include "qstring.h"
#include "tickets/template.h"
#include "qhash.h"

class Constantes{
private:
    Constantes();
    static Constantes * instancia;
    Template config;
public:
    static Constantes * getInstancia();
    QString getLogo();
    QString getTemplate(QString template_name);
    QString getPrinter(QString printer_name);
    QString getLogin(QString login_key);
    QString getServerURL();
    QString getService(QString service_name, QHash<QString, QString> data);
    QString getTokenName();
    QString getTokenKey();
    QString getTokenService();
    QString getAllow();
    QHash<QString, QString> getLogin();

};

#endif // CONSTANTES_H
