//
// Created by tomer on 27/12/2019.
//

#include "ConnectControlClientCommand.h"
//#include "main.cpp"

extern queue<string> queue1;

ConnectControlClientCommand::ConnectControlClientCommand() {}

int ConnectControlClientCommand::execute(vector<string> myVector, int index) {
    //interpert to the port
    string portString = myVector[index + 2];
    portString.erase(remove(portString.begin(), portString.end(), ' '), portString.end());
    //convert ip from string to char *
    string ipString = myVector[index + 1];
    int len = ipString.length();
    char *ip = (char *) calloc(len, sizeof(char));
    int i;
    for (i = 0; i <= sizeof(ip); i++) {
        ip[i] = ipString[i];
    }

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
    thread myThread(&ConnectControlClientCommand::connectClient, this, ip, port);
    //let the thread work
    myThread.detach();

    return 3;
}

void ConnectControlClientCommand::connectClient(char *ip, int port) {
    //create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
    }

    //We need to create a sockaddr obj to hold address of server
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;//IP4
    address.sin_addr.s_addr = inet_addr(ip);  //the localhost address
    address.sin_port = htons(port);
    //we need to convert our number (both port & localhost)
    // to a number that the network understands.

    // Requesting a connection with the server on local host with port 8081
    int is_connect = connect(client_socket, (struct sockaddr *) &address, sizeof(address));
    if (is_connect == -1) {
        std::cerr << "Could not connect to host server" << std::endl;
    } else {
        std::cout << "Client is now connected to server" << std::endl;
    }
    //if here we made a connection
    while (this->mapsSingeltonClass1.getCheckIfDone()) {
        //check if the queue is not empty
        if (!queue1.empty()) {
            //stop the other threads
            std::mutex mutex_lock;
            mutex_lock.lock();
            //take the first one in the queue
            string firstString = queue1.front();
            //convert the string to char *
            int len = firstString.length();
            char *first = new char[len + 1];
            strcpy(first, firstString.c_str());
            //pop the first string in the queue
            queue1.pop();
            // doing set in the simolator (send the path of the var we want to change and the value we want to put there)
            int is_sent = send(client_socket, first, strlen(first), 0);
            if (is_sent == -1) {
                std::cout << "Error sending message" << std::endl;
            }
            //let the other threads work again
            mutex_lock.unlock();
        }
    }

    close(client_socket);
}
