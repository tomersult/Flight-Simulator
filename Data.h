//
// Created by oriel on 17/12/2019.
//

#ifndef EX3_DATA_H
#define EX3_DATA_H

#include "Expression.h"
#include <iostream>
#include "ex1.h"
/**
 * this class is holding the data of the value and the path of the
 * varible we hace a connection to the simulator.
 */

using namespace std;

class Data {
public:
    Data();

    Data(string simAdress, Expression *value1);


    Expression *getValue() const;

    const string &getSimAdress() const;

    void setValue(Expression *value);

    void setSimAdress(const string &simAdress);

private:
    Expression *value;
    string simAdress;
};


#endif //EX3_DATA_H
