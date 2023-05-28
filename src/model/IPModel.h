#ifndef IPMODEL_H
#define IPMODEL_H

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class IPModel {
public:

    // Read any image file and store its data.
    virtual void read() = 0;

    /**
     * Appends the appropriate extension and makes an appropriate file name
     * given a name and image path.
     *
     * @param saveAsName the name to save this image as
     * @param imagePath  the path of the file.
     * @return the new full image file name
     */
    virtual string generateFileName(string saveAsName, string imagePath) = 0;
};

#endif