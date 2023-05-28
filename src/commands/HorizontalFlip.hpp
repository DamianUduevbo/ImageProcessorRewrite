#pragma once

#include <iostream>
#include <unordered_map>

#include "IPCommand.h"

using std::cout;
using std::endl;
using std::string;

class HorizontalFlip : public IPCommand {
public:
    void execute() override {
        cout << "executed Horizontal Flip" << endl;
    }

};