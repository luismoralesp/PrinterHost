#ifndef PRINTERHOST_H
#define PRINTERHOST_H
#include "PluginHost.h"
class PrinterHost: public PluginHost
{
public:
    PrinterHost();

    string onMessage(string msg);
};

#endif // PRINTERHOST_H
