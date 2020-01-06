//
// Created by oriel on 21/12/2019.
//
#ifndef EX3_MAPSSINGELTONCLASS_H
#define EX3_MAPSSINGELTONCLASS_H

#include <deque>
#include <queue>
#include<map>
#include "Data.h"
#include "Command.h"
#include <iostream>

using namespace std;
/**
 * using the SingeltonClass Design Pattern to make one show of
 * the singelton class.
 * this class have some members - the maps to make sure its the same maps
 * and every command can use them.
 * the interperter - have a map inside that remmeber all the variable
 * and know there value.
 * checkIfDone bool- a var that help to know when to finish the program.
 * and all the method of sets and gets that help to change stuff.
 */
class mapsSingeltonClass {

    Interpreter *interpreter1 = new Interpreter();
    map<string, Data> firstMapUser;
    map<string, Data> secoendMapOut;
    bool checkIfDone = true;
    queue<string> myQueue;

    mapsSingeltonClass() {}

    mapsSingeltonClass(mapsSingeltonClass const &);

    void operator=(mapsSingeltonClass const &);

public:
    static mapsSingeltonClass &getInstance() {
        static mapsSingeltonClass instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }

    const map<string, Data> &getFirstMapUser() const {
        return firstMapUser;
    }

    const map<string, Data> &getSecoendMapOut() const {
        return secoendMapOut;
    }

    void setFirstMapUser(const map<string, Data> &firstMapUser) {
        mapsSingeltonClass::firstMapUser = firstMapUser;
    }

    void setSecoendMapOut(const map<string, Data> &secoendMapOut) {
        mapsSingeltonClass::secoendMapOut = secoendMapOut;
    }

    Interpreter *getInterpreter1() const {
        return interpreter1;
    }

    void setInterpreter1(Interpreter *interpreter1) {
        mapsSingeltonClass::interpreter1 = interpreter1;
    }

    const bool &getCheckIfDone() const {
        return checkIfDone;
    }

    void setCheckIfDone(const bool &checkIfDone) {
        mapsSingeltonClass::checkIfDone = checkIfDone;
    }

    const queue<string> &getMyQueue() const {
        return myQueue;
    }

    void setMyQueue(const queue<string> &myQueue) {
        mapsSingeltonClass::myQueue = myQueue;
    }
};

#endif







