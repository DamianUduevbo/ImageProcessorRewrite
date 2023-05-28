#pragma once
#include "model/ImageData.h"

class Debug {
public:
    static void PrintAllArgs(int& argc, char** argv) {
        cout << "========== DEBUG INFO ==========" << endl;
        cout << "Number of arguments: " << argc << endl;
        cout << "Args:" << &argv << endl;
        
        for (int i = 0; i < argc; i++) {
            cout << "Argument number " << i << ": " << argv[i] << endl;
        }

        cout << "================================" << "\n" << endl;
    }

    static void PrintImageInfo(const ImageData& imageStruct) {
        cout << "width: " << imageStruct.width << endl;
        cout << "height: " << imageStruct.height << endl;
        cout << "numChannels: " << imageStruct.numChannels << endl;
        cout << "imageData: " << imageStruct.imageData << endl;
        return;
    }
};
