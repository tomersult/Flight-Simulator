//
// Created by oriel on 17/12/2019.
//

#ifndef EX3_OPENDATASERVERCOMMAND_H
#define EX3_OPENDATASERVERCOMMAND_H

#include <iostream>
#include <map>
#include "Command.h"
#include "Data.h"
#include <sys/socket.h>
#include <string.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <stdio.h>
#include <thread>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include "ex1.h"

class openDataServerCommand : public Command {
public:
    openDataServerCommand();
    int execute(vector<string> myVector, int index) ;
    vector<string> split(string s, char delimiter);
    map<string,Data> sendToEnterMap (map<string,Data> &map ,vector<string> v);
    void openSocket(int port);
};



#endif //EX3_OPENDATASERVERCOMMAND_H
