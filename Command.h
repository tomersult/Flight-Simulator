//
// Created by oriel on 15/12/2019.
//


#ifndef EX3_COMMAND_H
#define EX3_COMMAND_H

#include<unordered_map>
#include "mapsSingeltonClass.h"
#include <vector>
#include <list>
#include <iostream>
#include "Data.h"
#include "parserClass.h"
#include<queue>
#include <map>

using namespace std;

class Command {
public:
    virtual int execute(vector<string> myVector, int index) = 0;

    Command() {};

    virtual ~Command() {};

protected:
    mapsSingeltonClass &mapsSingeltonClass1 = mapsSingeltonClass::getInstance();

};

#endif //EX3_COMMAND_H
