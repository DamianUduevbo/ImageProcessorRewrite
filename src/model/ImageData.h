#pragma once

#include <iostream>
//#include "stb_image.h"

using std::cout;
using std::endl;

struct ImageData {
    int width;
    int height;
    int numChannels;
    unsigned char** imageData;

    //default constructor
    ImageData() : width(0), height(0), numChannels(0), imageData(nullptr) {
        cout << "constructor called" << endl;
    };

    //copy constructor
    ImageData(const ImageData& imageStruct) {
        cout << "copy constructor called" << endl;

        width = imageStruct.width;
        height = imageStruct.height;
        numChannels = imageStruct.numChannels;
        imageData = imageStruct.imageData;
    };

    //destructor
    ~ImageData() {
        cout << "destructor called" << endl;
        delete imageData;
        //stbi_image_free(imageData);
    };

    // returns RBG matrix of a pixel at (x, y)
    int* getPixel(int x, int y) {
        int pixel[3];
        int index = (y * width + x) * numChannels;

        for (int i = 0; i < numChannels; i++) {
            // pixel[i] = imageData[index + i];
        }

        return pixel;
    };
};
