

#ifndef EX3_DEFINEVARCOMMAND_H
#define EX3_DEFINEVARCOMMAND_H


#include <map>
#include <list>
#include <vector>
#include <iostream>
#include "Lexer.h"
#include "Data.h"
#include "Command.h"

using namespace std;


class DefineVarCommand : public Command {
public:
    DefineVarCommand();

    int execute(vector<string> myVector, int index);

    ~DefineVarCommand() {};

private:

};


#endif //EX3_DEFINEVARCOMMAND_H
