#ifndef IPCONTROLLER_H
#define IPCONTROLLER_H
#include <string>
#include <iostream>

using String = std::string;
using std::cout;
using std::endl;

class IPController {
public:
    virtual void run() = 0;

    // takes both rvalues and lvalues
    virtual void load(const String& imageName, const String& imagePath) = 0;

    // takes just rvalues
    virtual void load(const String&& imageName, const String&& imagePath) = 0;

    // takes both rvalues and lvalues
    virtual void save(
        const String& imageName,
        const String& saveAsName,
        const String& imagePath,
        const String& extension
    ) = 0;

    // takes just rvalues
    virtual void save(
        const String&& imageName,
        const String&& saveAsName,
        const String&& imagePath,
        const String&& extension
    ) = 0;
};

#endif