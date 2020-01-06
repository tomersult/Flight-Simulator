//
// Created by tomer on 29/12/2019.
//

#ifndef FILGHTSIMOLATOR_SLEEPCOMMAND_H
#define FILGHTSIMOLATOR_SLEEPCOMMAND_H

#include "Command.h"
#include <iostream>


class sleepCommand : public Command {
public:
    sleepCommand();
    int execute(vector<string> myVector, int index);

};


#endif //FILGHTSIMOLATOR_SLEEPCOMMAND_H
