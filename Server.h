//
// Created by conn on 22/09/2021.
//

#ifndef NETWORKS_SERVER_H
#define NETWORKS_SERVER_H


#include "Node.h"

class Server: public Node{
public:
    char *connectedMessage = "Server received message";
    Server();
    void startServer();

    int main();
};


#endif //NETWORKS_SERVER_H
