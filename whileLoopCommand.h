//
// Created by oriel on 22/12/2019.
//

#ifndef EX3_WHILELOOPCOMMAND_H
#define EX3_WHILELOOPCOMMAND_H

#include "Command.h"
#include "parserClass.h"


class whileLoopCommand : public Command {

public:
    whileLoopCommand() {};

    int execute(vector<string> myVector, int index);

    bool check(string first, string secoend, string sign);

};


#endif //EX3_WHILELOOPCOMMAND_H_
