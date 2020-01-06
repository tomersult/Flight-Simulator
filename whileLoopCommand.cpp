//
// Created by oriel on 22/12/2019.
//

#include <algorithm>
#include "whileLoopCommand.h"


int whileLoopCommand::execute(vector<string> myVector, int index) {
    queue<string> myQueue = this->mapsSingeltonClass1.getMyQueue();
    map<string, Data> firstUserMap = this->mapsSingeltonClass1.getFirstMapUser();
    map<string, Data> secoendOutMap = this->mapsSingeltonClass1.getSecoendMapOut();
    //checking how much  we need to return in the end.
    int returnVal = 1;
    for (int j = index; j < myVector.size(); ++j) {
        if (myVector[j].compare("}")) {
            returnVal++;
        } else {
            break;
        }
    }
    int count = 1;
    int tempIndex = index + 1;
    string first = "";
    string secoend = "";
    string sign = "";
    // getting the first part of the condition(equation)
    while (myVector[tempIndex].compare("==") && myVector[tempIndex].compare("!=") &&
           myVector[tempIndex].compare("<=") && myVector[tempIndex].compare(">=")
           && myVector[tempIndex].compare("<")
           && myVector[tempIndex].compare(">")) {
        string s = myVector[tempIndex];
        first = first + myVector[tempIndex];
        tempIndex++;
        count++;
    }
    // the sign of the condition
    sign = myVector[tempIndex];
    count++;
    tempIndex++;
    //the secoenf part of the condition(equation)
    int search = 0;
    string token = "";
    //the secoenf part of the condition(equation)
    while (myVector[tempIndex].compare("{")) {
        if (myVector[tempIndex].find("{") != -1) {
            search = myVector[tempIndex].find("{");
            token = myVector[tempIndex].substr(0, search);
            secoend = secoend + token;
            break;
        }
        secoend = secoend + myVector[tempIndex];
        tempIndex++;
        count++;
    }
    // insert to the vector all the string that in the scope of the if
    //that mean all the string between '{' to '}'.
    vector<string> newVector;
    int checkHowMany = 0;
    for (int i = tempIndex + 1; i < myVector.size(); i++) {
        if (myVector[i].compare("}")) {
            newVector.push_back(myVector[i]);
            checkHowMany++;
        } else {
            break;
        }
    }
//removing unnecessary space.
    first.erase(remove(first.begin(), first.end(), ' '), first.end());
    secoend.erase(remove(secoend.begin(), secoend.end(), ' '), secoend.end());
    sign.erase(remove(sign.begin(), sign.end(), ' '), sign.end());
    // sending the condition part to a function that will check if
    // to make the lines in the scope or not.
    // and it will do it while(!!) the function will send true.
    while (check(first, secoend, sign) == true) {
        //sending to the parserClass again, with a new vector
        // that made of the scope of the if.
        parserClass newparserClass11(newVector, 0);
        newparserClass11.parse();
    }

    return returnVal;
}

bool whileLoopCommand::check(string first, string secoend, string sign) {

    /**
    * this func is checking if the condition is true or false
    * by checking the two side of the eqasion and check which one is bigger
    * for general which condition we get from the fly.txt
    */
    //caculating bothe side of the equation
    Expression *expression1 = nullptr;
    try {
        expression1 = this->mapsSingeltonClass1.getInterpreter1()->interpret(first);
    } catch (const char *e) {
        if (expression1 != nullptr) {
            delete expression1;
        } //deleting i2 in the next example
    }
    Expression *expression2 = nullptr;
    try {
        expression2 = this->mapsSingeltonClass1.getInterpreter1()->interpret(secoend);
    } catch (const char *e) {
        if (expression2 != nullptr) {
            delete expression2;
        } //deleting i2 in the next example
    }
    double firstExp = expression1->calculate();
    double secoendExp = expression2->calculate();
// check if the condition is true.
    if (sign == ">") {
        if (firstExp > secoendExp) {
            return true;
        } else {
            return false;
        }


    } else if (sign == "<") {
        if (firstExp < secoendExp) {
            return true;
        } else {
            return false;
        }


    } else if (sign == ">=") {
        if (firstExp >= secoendExp) {
            return true;
        } else {
            return false;
        }


    } else if (sign == "<=") {
        if (firstExp <= secoendExp) {
            return true;
        } else {
            return false;
        }


    } else if (sign == "==") {
        if (firstExp == secoendExp) {
            return true;
        } else {
            return false;
        }
    } else if (sign == "!=") {
        if (firstExp != secoendExp) {
            return true;
        } else {
            return false;
        }

    } else {
        __throw_bad_exception();
    }

}


