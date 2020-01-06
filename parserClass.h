//
// Created by oriel on 22/12/2019.
//

#ifndef EX3_PARSERCLASS_H
#define EX3_PARSERCLASS_H

#include <vector>
#include <iostream>
#include <map>
#include <list>
#include "Command.h"
#include "Lexer.h"
#include "Data.h"



using namespace std;

class parserClass {
public:
    parserClass(vector<string> myVector1, int index);

    void parse();

private:
    vector<string> myVector;
    int index;
};


#endif //EX3_PARSERCLASS_H
