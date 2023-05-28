#ifndef IPCOMMAND_H
#define IPCOMMAND_H

#include <string>
#include <iostream>

using String = std::string;
using std::cout;
using std::endl;

class IPCommand {
public:
    virtual void execute() = 0;
};

#endif