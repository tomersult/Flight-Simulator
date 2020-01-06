//
// Created by oriel on 22/12/2019.
//

#include "parserClass.h"
#include "DefineVarCommand.h"
#include "whileLoopCommand.h"
#include "printCommand.h"
#include "ifCommand.h"
#include "openDataServerCommand.h"
#include <queue>
#include "ConnectControlClientCommand.h"
#include "sleepCommand.h"

parserClass::parserClass(vector<string> myVector1, int index) {
    this->index = index;
    this->myVector = myVector1;
}

/**
 * the parser class- the class that actually run all the program.
 * the class get a vector with string of information what to do.
 * and an index to where to start in the vector.
 * the class run on the vector and make the program like that.
 */
void parserClass::parse() {
    int flag = 0;
    /**
     * insert to the map of <string,command> the string and the
     * class that much to that string.
     */
    map<string, Command *> commandMap;
    commandMap.emplace("var", new DefineVarCommand());
    commandMap.emplace("while", new whileLoopCommand());
    commandMap.emplace("Print", new printCommand());
    commandMap.emplace("if", new ifCommand());
    commandMap.emplace("openDataServer", new openDataServerCommand());
    commandMap.emplace("connectControlClient", new ConnectControlClientCommand());
    commandMap.emplace("Sleep", new sleepCommand());
    vector<string> vectornew = this->myVector;
    int size = this->myVector.size() - 1;
    // runing on all the vector.
    while (this->index <= size) {
        /**
         * trying to find a key word in the map.
         * the key word is:var,if,while,print,openServer,conncetControlClient,Sleep.
         * if we find one of them we are taking the maching command and because
         * command is an "interface" we are doing a general execute and its execute the
         * muching command that we got from the map.
         * the execute function getting the vector and the index
         * that we are current at in the vector.
         */
        if (this->myVector[this->index] == "var" || this->myVector[this->index] == "if" ||
            this->myVector[this->index] == "while" || this->myVector[this->index] == "Print"
            || this->myVector[this->index] == "openDataServer" || this->myVector[this->index] == "connectControlClient"
            || this->myVector[this->index] == "Sleep") {
            Command *c = commandMap.at(this->myVector[this->index]);
            if (c != NULL) {
                this->index += c->execute(this->myVector, this->index);
            }
            /**
             * if we cant find one of the key word we are getting tho the execute
             * of the DefineVarCommand. its for all the
             * lines we are making assignment and stuff like that.
             */
        } else {
            DefineVarCommand *c = new DefineVarCommand();
            this->index += c->execute(this->myVector, this->index);
        }
    }
}
