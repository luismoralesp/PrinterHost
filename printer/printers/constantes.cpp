#include "printer/constantes.h"
#include "qfile.h"
#include "qdebug.h"
Constantes * Constantes::instancia = NULL;

Constantes::Constantes(): config(Template(CONFIG_FILE)){

}

Constantes * Constantes::getInstancia(){
    if (instancia == NULL){
        instancia = new Constantes();
    }
    return instancia;
}

QString Constantes::getLogo(){
    return config.findInTemplate("logo");
}

QString Constantes::getTemplate(QString template_name){
    QString templates = config.findInTemplate("templates");
    QString template_ = Template::findInString(templates, template_name);
    return template_;

}

QString Constantes::getPrinter(QString printer_name){
    QString printers = config.findInTemplate("printers");
    QString printer = Template::findInString(printers, printer_name);
    return printer;
}

QString Constantes::getLogin(QString login_key){
    QString login = config.findInTemplate("login");
    QString value = Template::findInString(login, login_key);
    return value;
}

QString Constantes::getServerURL(){
    return config.findInTemplate("url");
}

QString Constantes::getService(QString service_name, QHash<QString, QString> data){
    QString services = config.findInTemplate("services");

    QString service = Template::findInString(services, service_name);

    QHash<QString, QString>::iterator it;
    for (it = data.begin(); it != data.end(); it++){
        service = service.replace("{{" + it.key() + "}}", it.value());
    }
    return service;
}


QString Constantes::getTokenName(){
    QString token = config.findInTemplate("token");
    return  Template::findInString(token, "name");
}

QString Constantes::getTokenKey(){
    QString token = config.findInTemplate("token");
    return  Template::findInString(token, "key");
}

QString Constantes::getTokenService(){
    QString token = config.findInTemplate("token");
    return  Template::findInString(token, "service");
}

QString Constantes::getAllow(){
    return config.findInTemplate("allow");
}

QHash<QString, QString> Constantes::getLogin(){
    QString login = config.findInTemplate("login");

}
