//
// Created by oriel on 15/12/2019.
//

#include "DefineVarCommand.h"
#include <algorithm>
#include <queue>
//#include "main.cpp"

extern queue<string> queue1;

DefineVarCommand::DefineVarCommand() {}

int DefineVarCommand::execute(vector<string> myVector, int index) {
    //intiilaize vars - the maps and the string to push to the queue
    string pushToMyQueue = "";
    map<string, Data> firstUserMap = this->mapsSingeltonClass1.getFirstMapUser();
    map<string, Data> secoendOutMap = this->mapsSingeltonClass1.getSecoendMapOut();
    Data data;
    //check if we have "->" to know to which map to push var name and path.
    if (myVector[index + 2] == "->") {
        // remove all the from the string".
        myVector[index + 3].erase(remove(myVector[index + 3].begin(),
                                         myVector[index + 3].end(), '\"'),
                                  myVector[index + 3].end());
        //put the path in the data.
        data.setSimAdress(myVector[index + 3]);
        firstUserMap.emplace(myVector[index + 1], data);
        this->mapsSingeltonClass1.setFirstMapUser(firstUserMap);
        return 4;
        //check if we have "<-" to know to which map to push var name and path.
    } else if (myVector[index + 2] == "<-") {
        // remove all the from the string".
        myVector[index + 3].erase(remove(myVector[index + 3].begin(),
                                         myVector[index + 3].end(), '\"'),
                                  myVector[index + 3].end());
        //put the path ad the key.
        //put the name as the simadress in the data.
        data.setSimAdress(myVector[index + 1]);
        secoendOutMap.emplace(myVector[index + 3], data);
        this->mapsSingeltonClass1.setSecoendMapOut(secoendOutMap);
        return 4;
        // if ths string we check dosent have the word var and the operaor "=".
        //that's mean we fill the data that we have a path in it with his value.
        // for example alt = 5
    } else if ((myVector[index].compare("var")) && myVector[index + 1] == "=") {
        string path = "";
        //the value
        string index2 = myVector[index + 2];
        //remove spaces
        index2.erase(remove(index2.begin(), index2.end(), ' '), index2.end());
        //caulating the value of the equation.
        Expression *e;
        try {
            e = this->mapsSingeltonClass1.getInterpreter1()->interpret(index2);
        } catch (const char *e) {
            if (e != nullptr) {
                delete e;
            }
            if (e != nullptr) {
                delete e;
            }
        }

        double num = e->calculate();
        //changing from double to string
        string temp = "";
        ostringstream strs;
        strs << num;
        string str = strs.str();
        //removing the spaces
        myVector[index].erase(remove(myVector[index].begin(),
                                     myVector[index].end(), ' '),
                              myVector[index].end());
        //send to the set variable the value with the var.
        temp = myVector[index] + "=" + str;
        this->mapsSingeltonClass1.getInterpreter1()->setVariables(temp);
        //check to which map to update the value of the var in Data.
        if (firstUserMap.find(myVector[index]) == firstUserMap.end()) {
        } else {
            firstUserMap[myVector[index]].setValue(e);
            path = firstUserMap[myVector[index]].getSimAdress();
            this->mapsSingeltonClass1.setFirstMapUser(firstUserMap);
        }
        map<string, Data>::iterator it;
        for (it = secoendOutMap.begin(); it != secoendOutMap.end(); it++) {
            if (it->second.getSimAdress() == myVector[index]) {
                it->second.setValue(e);
                path = it->first;
                this->mapsSingeltonClass1.setSecoendMapOut(secoendOutMap);
            }
        }

        pushToMyQueue = "set " + path + " " + str + "\r\n";
        // push to the Queue the set order.
        if (!pushToMyQueue.empty()) {
            queue1.push(pushToMyQueue);
        }
        return 3;
        //if we are having assigment of a var with over var
        // i put the value of var in the new var
    } else if (myVector[index] == "var" && myVector[index + 2] == "=") {
        int caculate = 0;
        //remove spaces
        myVector[index + 3].erase(remove(myVector[index + 3].begin(),
                                         myVector[index + 3].end(), ' '),
                                  myVector[index + 3].end());
        Expression *expression = nullptr;
        try {
            // cauculatin the number of the var.
            expression = this->mapsSingeltonClass1.getInterpreter1()->interpret(myVector[index + 3]);
            caculate = expression->calculate();
            delete expression;
        } catch (const char *e) {
            if (expression != nullptr) {
                delete expression;
            }
        }
        // we are not entering the var in to the amp because thre is no path!
        // we put it in the the setvariable map to interpet eqausion.
        string temp1 = "";
        ostringstream strs;
        strs << caculate;
        string str = strs.str();
        temp1 = myVector[index + 1] + "=" + str;
        this->mapsSingeltonClass1.getInterpreter1()->setVariables(temp1);
        return 4;
    } else {
        return 0;
    }

}


