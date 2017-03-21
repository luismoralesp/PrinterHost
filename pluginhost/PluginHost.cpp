/* 
 * @file:   PluginHost.cpp
 * @author: Luis Miguel Morales
 * @business: Carotech SAS
 * @date: 03-06-2014
 * 
 */
#include "PluginHost.h"
#include <stdio.h>
#include "printer/constantes.h"

PluginHost::PluginHost() {
}

PluginHost::PluginHost(const PluginHost& orig) {
}

PluginHost::~PluginHost() {
}

void PluginHost::log(string log) {
    log += "\n";
    FILE * file = fopen("C:\\Users\\Public\\Documents\\pluginhost.log", "a+");
    fprintf(file, log.c_str());
    fclose(file);
}

string PluginHost::input() {
    std::cout.setf(std::ios_base::unitbuf); //instead of "<< eof" and "flushall"
    unsigned int c;
    unsigned int size = 0;
    string inp = "";
    // Sum the first 4 chars from stdin (the length of the message passed).
    for (int i = 0; i < 4; i++) {
        size += getchar();
    }

    // Loop getchar to pull in the message until we reach the total
    //  length provided.
    for (int i = 0; i < size; i++) {
        c = getchar();
        inp += c;
    }
    return inp;
}

void PluginHost::output(string msg) {
    unsigned int len = msg.length();
    //// We need to send the 4 btyes of length information
    cout << char(((len >> 0) & 0xFF))
            << char(((len >> 8) & 0xFF))
            << char(((len >> 16) & 0xFF))
            << char(((len >> 24) & 0xFF));
    //// Now we can output our message
    cout << msg;
}

void PluginHost::start() {
    string inp = "{\"data\":{\"id\":\"108\"}, \"service\":\"bill\", \"printer\": \"chef\", \"template\":\"bill\" }";//input();
    string out = onMessage(inp);
    //
    delete Constantes::getInstancia();
    //output(out);
}
