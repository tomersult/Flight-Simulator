//
// Created by tomer on 27/12/2019.
//
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
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "mapsSingeltonClass.h"
#include <mutex>

#ifndef FILGHTSIMOLATOR_CONNECTCONTROLCLIENTCOMMAND_H
#define FILGHTSIMOLATOR_CONNECTCONTROLCLIENTCOMMAND_H


class ConnectControlClientCommand :public Command {
public:
    ConnectControlClientCommand();
    int execute(vector<string> myVector, int index);
    void connectClient(char *ip , int port);
};


#endif //FILGHTSIMOLATOR_CONNECTCONTROLCLIENTCOMMAND_H
