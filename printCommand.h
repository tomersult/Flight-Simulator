//
// Created by tomer on 17/12/2019.
//

#ifndef EX3_PRINTCOMMAND_H
#define EX3_PRINTCOMMAND_H

#include "Command.h"


class printCommand : public Command {

public:
    printCommand() {};

    int execute(vector<string> myVector, int index);

    ~printCommand() {};

};


#endif //EX3_PRINTCOMMAND_H