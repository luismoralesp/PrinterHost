#-------------------------------------------------
#
# Project created by QtCreator 2014-06-27T17:20:36
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PrinterHost
TEMPLATE = app

RC_FILE += PrinterHost.rc

SOURCES += \
    pluginhost/PluginHost.cpp \
    pluginhost/printerhost.cpp \
    printer/barcode/code128.cpp \
    printer/barcode/code128item.cpp \
    printer/printers/diaprinter.cpp \
    printer/printers/reciboprinter.cpp \
    printer/printers/ticketprinter.cpp \
    printer/tickets/diaticket.cpp \
    printer/tickets/reciboticket.cpp \
    printer/tickets/template.cpp \
    printer/tickets/ticket.cpp \
    printer/printercontroller.cpp \
    printer/ticketcontroller.cpp \
    server/serverconector.cpp \
    main.cpp \
    mainwindow.cpp \
    printer/tickets/billticket.cpp \
    printer/printers/billprinter.cpp \
    printer/printers/constantes.cpp \
    http/httpserver.cpp \
    http/httpresponse.cpp \
    http/printerserver.cpp \
    http/httprequest.cpp

HEADERS  += \
    pluginhost/PluginHost.h \
    pluginhost/printerhost.h \
    printer/barcode/code128.h \
    printer/barcode/code128item.h \
    printer/printers/diaprinter.h \
    printer/printers/reciboprinter.h \
    printer/printers/ticketprinter.h \
    printer/tickets/diaticket.h \
    printer/tickets/reciboticket.h \
    printer/tickets/template.h \
    printer/tickets/ticket.h \
    printer/constantes.h \
    printer/printercontroller.h \
    printer/ticketcontroller.h \
    server/serverconector.h \
    mainwindow.h \
    printer/tickets/billticket.h \
    printer/printers/billprinter.h \
    http/httpserver.h \
    http/httpresponse.h \
    http/printerserver.h \
    http/httprequest.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc

DISTFILES += \
    PrinterHost.rc
