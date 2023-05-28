#ifndef IPVIEW_H
#define IPVIEW_H

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class IPView {
public:
    // takes both rvalues and lvalues
    virtual void renderMessage(const string& message) = 0;

    // takes only rvalues
    virtual void renderMessage(const string&& message) = 0;
};

#endif