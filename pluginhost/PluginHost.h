/* 
 * @file:   PluginHost.h
 * @author: Luis Miguel Morales
 * @business: Carotech SAS
 * @date: 03-06-2014
 * 
 */

#ifndef PLUGINHOST_H
#define	PLUGINHOST_H
#include <iostream>
using namespace std;
class PluginHost {
public:
    PluginHost();
    PluginHost(const PluginHost& orig);
    virtual ~PluginHost();
    
    virtual string onMessage(string msg) = 0;
    virtual void log(string log);
    
    string input();
    void output(string msg);
    void start();
    
private:

};

#endif	/* PLUGINHOST_H */

