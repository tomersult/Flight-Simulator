//
// Created by tomer on 29/12/2019.
//

#include "sleepCommand.h"
#include <chrono>
#include <thread>


sleepCommand::sleepCommand() {};

int sleepCommand::execute(vector<string> myVector, int index) {
    string time = myVector[index + 1];
    myVector[index + 1].erase(remove(myVector[index + 1].begin(),
                                     myVector[index + 1].end(), ' '),
                              myVector[index + 1].end());
    int caculate = 0;
    //enter the x the tome we want to do sleep
    Expression *expression = nullptr;
    try {
        // cauculatin the number of the var.
        expression = this->mapsSingeltonClass1.getInterpreter1()->interpret(myVector[index + 1]);
        caculate = expression->calculate();
        delete expression;
    } catch (const char *e) {
        if (expression != nullptr) {
            delete expression;
        }
    }


    //sleep the main
    std::this_thread::sleep_for(std::chrono::milliseconds(caculate));
    return 2;
}
//    stringstream geek(time);
//    int x = 0;
//    geek >> x;