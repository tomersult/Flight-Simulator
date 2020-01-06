//
// Created by oriel on 17/12/2019.
//

#include "Data.h"

Data::Data(string simAdress1, Expression *expression) {
    this->value = expression;
    this->simAdress = simAdress1;
}

Data::Data() {}

Expression *Data::getValue() const {
    return value;
}

const string &Data::getSimAdress() const {
    return simAdress;
}

void Data::setValue(Expression *value) {
    Data::value = value;
}

void Data::setSimAdress(const string &simAdress) {
    Data::simAdress = simAdress;
}


