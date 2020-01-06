//
// Created by oriel on 17/12/2019.
//

#include "openDataServerCommand.h"
#include <mutex>

static bool stopMain = true;

openDataServerCommand::openDataServerCommand() {}

vector<string> openDataServerCommand::split(string s, char delimiter) {
    string value(s);
    vector<string> v;
    // check where is the first \n
    string line = value.substr(0, value.find_first_of('\n'));
    size_t num = std::count(line.begin(), line.end(), delimiter);
    if (num != 35) {
        line = "";
        //updating the line
        for (int k = 0; k < 1024; k++) {
            if (s[k] == '\n') {
                k++;
                while (s[k] != '\n') {
                    line += s[k];
                    k++;
                }
                break;
            }
        }
    }
    string::size_type i = 0;
    string::size_type j = line.find(delimiter);
    //split with ','
    while (j != string::npos) {
        v.push_back(line.substr(i, j - i));
        i = ++j;
        j = line.find(delimiter, j);

        if (j == string::npos)
            v.push_back(line.substr(i, line.length()));
    }
    return v;

}


map<string, Data> openDataServerCommand::sendToEnterMap(map<string, Data> &map, vector<string> v) {
    string line;
    ifstream inFile;
    string value;
    //stop the other threads when this func updating the map of the enter values from the simolator
    std::mutex mutex_lock;
    mutex_lock.lock();

    for (const auto &p : map) {
        int index = 100;
        // we didn't know if you read from the "generic_small.xml" in the check so we write the two option:
        //1)we check what the index in the vector of values without read from the file
        //2)to read from the xml file

        //the manual check , check if the path in the map is the same like the path in one of the value in the xml file
        if (p.first.find("/instrumentation/airspeed-indicator/indicated-speed-kt") != string::npos) {
            index = 0;
        }
        if (p.first.find("/sim/time/warp") != string::npos) {
            index = 1;
        }
        if (p.first.find("/controls/switches/magnetos") != string::npos) {
            index = 2;
        }
        if (p.first.find("/instrumentation/heading-indicator/offset-deg") != string::npos) {
            index = 3;
        }
        if (p.first.find("/instrumentation/altimeter/indicated-altitude-ft") != string::npos) {
            index = 4;
        }
        if (p.first.find("/instrumentation/altimeter/pressure-alt-ft") != string::npos) {
            index = 5;
        }
        if (p.first.find("/instrumentation/attitude-indicator/indicated-pitch-deg") != string::npos) {
            index = 6;
        }
        if (p.first.find("/instrumentation/attitude-indicator/indicated-roll-deg") != string::npos) {
            index = 7;
        }
        if (p.first.find("/instrumentation/attitude-indicator/internal-pitch-deg") != string::npos) {
            index = 8;
        }
        if (p.first.find("/instrumentation/attitude-indicator/internal-roll-deg") != string::npos) {
            index = 9;
        }
        if (p.first.find("/instrumentation/encoder/indicated-altitude-ft") != string::npos) {
            index = 10;
        }
        if (p.first.find("/instrumentation/encoder/pressure-alt-ft") != string::npos) {
            index = 11;
        }
        if (p.first.find("/instrumentation/gps/indicated-altitude-ft") != string::npos) {
            index = 12;
        }
        if (p.first.find("/instrumentation/gps/indicated-ground-speed-kt") != string::npos) {
            index = 13;
        }
        if (p.first.find("/instrumentation/gps/indicated-vertical-speed") != string::npos) {
            index = 14;
        }
        if (p.first.find("/instrumentation/heading-indicator/indicated-heading-deg") != string::npos) {
            index = 15;
        }
        if (p.first.find("/instrumentation/magnetic-compass/indicated-heading-deg") != string::npos) {
            index = 16;
        }
        if (p.first.find("/instrumentation/slip-skid-ball/indicated-slip-skid") != string::npos) {
            index = 17;
        }
        if (p.first.find("/instrumentation/turn-indicator/indicated-turn-rate") != string::npos) {
            index = 18;
        }
        if (p.first.find("/instrumentation/vertical-speed-indicator/indicated-speed-fpm") != string::npos) {
            index = 19;
        }
        if (p.first.find("/controls/flight/aileron") != string::npos) {
            index = 20;
        }
        if (p.first.find("/controls/flight/elevator") != string::npos) {
            index = 21;
        }
        if (p.first.find("/controls/flight/rudder") != string::npos) {
            index = 22;
        }
        if (p.first.find("/controls/flight/flaps") != string::npos) {
            index = 23;
        }
        if (p.first.find("/controls/engines/engine/throttle") != string::npos) {
            index = 24;
        }
        if (p.first.find("/controls/engines/current-engine/throttle") != string::npos) {
            index = 25;
        }
        if (p.first.find("/controls/switches/master-avionics") != string::npos) {
            index = 26;
        }
        if (p.first.find("/controls/switches/starter") != string::npos) {
            index = 27;
        }
        if (p.first.find("/engines/active-engine/auto-start") != string::npos) {
            index = 28;
        }
        if (p.first.find("/controls/flight/speedbrake") != string::npos) {
            index = 29;
        }
        if (p.first.find("/sim/model/c172p/brake-parking") != string::npos) {
            index = 30;
        }
        if (p.first.find("/controls/engines/engine/primer") != string::npos) {
            index = 31;
        }
        if (p.first.find("/controls/engines/current-engine/mixture") != string::npos) {
            index = 32;
        }
        if (p.first.find("/controls/switches/master-bat") != string::npos) {
            index = 33;
        }
        if (p.first.find("/controls/switches/master-alt") != string::npos) {
            index = 34;
        }
        if (p.first.find("/engines/engine/rpm") != string::npos) {
            index = 35;
        }
        if (index >= 0 && index <= 35) {
            // if the path in the map equal to the path in the xml file we enter
            //the value of the var from the simolator to the map
            if (v[index] != "") {
                value = v[index];
            } else {
                value = v[index];
            }
            //convert the string to expresion because we have a field of expresion in the map (not a double)
            std::map<string, Data>::iterator it = map.find(p.first);
            Interpreter *i1 = new Interpreter();
            Expression *e1 = i1->interpret(value);
            it->second.setValue(e1);
            // updating the map of the values that enter from the simolator
            this->mapsSingeltonClass1.setSecoendMapOut(map);
            string temp;
            temp = it->second.getSimAdress() + "=" + value;
            // updating the map of set variables
            this->mapsSingeltonClass1.getInterpreter1()->setVariables(temp);
        }
    }
    //let the other threads return to work
    mutex_lock.unlock();
    return map;
}

int openDataServerCommand::execute(vector<string> myVector, int index) {
    //interpert to the port
    string portString = myVector[index + 1];
    portString.erase(remove(portString.begin(), portString.end(), ' '), portString.end());
    index += 2;
    int port;
    Interpreter *i1 = new Interpreter();
    Expression *e1 = nullptr;
    try {
        // 7
        e1 = i1->interpret(portString);
        port = e1->calculate();
        delete e1;
        delete i1;
    } catch (const char *e) {
        if (e1 != nullptr) {
            delete e1;
        }
        if (i1 != nullptr) {
            delete i1;
        }
        std::cout << e << std::endl;
    }

    thread myThread(&openDataServerCommand::openSocket, this, port);
    //stop the main till the socket will open
    while (stopMain) {}
    //let the thread work
    myThread.detach();

    return index;
}

void openDataServerCommand::openSocket(int port) {
/*    Expression* e = nullptr;
    map.emplace("/instrumentation/heading-indicator/offset-deg", new Data("heading",e));*/


    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        //throw ("Could not create a socket");
    }

    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);
    //we need to convert our number
    // to a number that the network understands.

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
        //throw ("Could not bind the socket to an IP" );
    }

    //making socket listen to the port
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr << "Error during listening command" << std::endl;
        //throw("Error during listening command");
    } else {
        std::cout << "Server is now listening ..." << std::endl;
        //reading from client
    }

    // accepting a client
    sockaddr aAddress;
    int client_socket = accept(socketfd, (struct sockaddr *) &aAddress,
                               (socklen_t *) &aAddress);
    if (client_socket == -1) {
        std::cerr << "Error accepting client" << std::endl;
    } else {
        std::cout << "Accepted" << std::endl;
    }
    close(socketfd); //closing the listening socket

    while (true) {
        map<string, Data> map = this->mapsSingeltonClass1.getSecoendMapOut();
        char buffer[1024] = {0};
        int valread = read(client_socket, buffer, 1024);
        char delimiter = ',';
        //split s to strings and put the strings in vector "v"
        vector<string> v = split(buffer, delimiter);

        //senf to func that enter the values to the map of enter values from simolator
        sendToEnterMap(map, v);
        stopMain = false;
    }
}



