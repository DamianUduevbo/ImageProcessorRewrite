#pragma once

#include <iostream>
#include <unordered_map>

#include "IPController.h"

using std::cout;
using std::endl;
using std::string;

class IPControllerImpl : public IPController {
public:
    IPControllerImpl() = default;

    void run() override {
        cout << "commands: quit(q), help,  commands, menu, load, save" << endl;
    }

    void load(const String& imageName, const String& imagePath) override {
        cout << "load: " << imageName << " " << imagePath << endl;
    }

    void load(const String&& imageName, const String&& imagePath) override {
        cout << "load: " << imageName << " " << imagePath << endl;
    }

    void save(
        const String& imageName,
        const String& saveAsName,
        const String& imagePath,
        const String& extension
    ) override {
        cout << "save: " << imageName << " " << saveAsName << " " << imagePath << " " << extension << endl;
    }

    void save(
        const String&& imageName,
        const String&& saveAsName,
        const String&& imagePath,
        const String&& extension
    ) override {
        cout << "save: " << imageName << " " << saveAsName << " " << imagePath << " " << extension << endl;
    }

private:
    std::unordered_map<string, string> commands;
};