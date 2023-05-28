#define STB_IMAGE_IMPLEMENTATION // define this macro to include the implementation of stb_image
#define STB_IMAGE_WRITE_IMPLEMENTATION // define this macro to include the implementation of stb_image_write
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <Windows.h>

#include "utils/stb_image.h"
#include "utils/stb_image_write.h"
#include "utils/Debugging.h"

#include "commands/IPCommand.h"
#include "commands/HorizontalFlip.hpp"

#include "controller/IPController.h"
#include "controller/IPControllerImpl.hpp"

#include "model/ImageData.h"
#include "model/IPModel.h"

using namespace std;

unsigned char** toMatrix(unsigned char* imageData, int& width, int& height, int& channels) {
    unsigned char** pixels = new unsigned char*[height];
    pixels[0] = new unsigned char[(width * height) * channels];
    for (int i = 1; i < height; i++) {
        pixels[i] = pixels[i - 1] + (width) * channels;
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = (i * width + j) * channels;
            for (int k = 0; k < channels; k++) {
                pixels[i][j * channels + k] = imageData[index + k];
            }
        }
    }
    return pixels;
}

int main(int argc, char* argv[2]) {
    const boolean DEBUG_MODE = true;

    ImageData imageStruct;
    unsigned char* loadedImageData;
    unsigned char** imageData;

    if (argv[1]) {
        loadedImageData = stbi_load(argv[1], &imageStruct.width, &imageStruct.height, &imageStruct.numChannels, 0);
        imageData = toMatrix(loadedImageData, imageStruct.width, imageStruct.height, imageStruct.numChannels);
        imageStruct.imageData = imageData;
    } else {
        throw invalid_argument("File not found.");
    }
    
    if (DEBUG_MODE) {
        Debug::PrintAllArgs(argc, argv);
        Debug::PrintImageInfo(imageStruct);
    }

    IPControllerImpl controllerImpl;
    controllerImpl.run();

    // Writing to file
    string saveAsName;
    cout << "Save as: " << endl;
    cin >> saveAsName;

    cout << "Saved as " << saveAsName << endl;
    return 0;
}
