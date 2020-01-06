//
// Created by oriel on 22/12/2019.
//

#ifndef EX3_IFCOMMAND_H
#define EX3_IFCOMMAND_H

#include "Command.h"
//#include "Interpreter.h"
#include "parserClass.h"

class ifCommand : public Command {
public:
    ifCommand();

    int execute(vector<string> myVector, int index);

    bool check(string first, string secoend, string sign);


};


#endif //EX3IFCOMMAND_H
