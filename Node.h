//
// Created by conn on 21/09/2021.
//

#ifndef NETWORKS_NODE_H
#define NETWORKS_NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
class Node {
protected:
    struct sockaddr_in address;
    char buffer[128] = {0};
    int socket_fd, port_number;
public:
    Node(int port_number = 69420);
};


#endif //NETWORKS_NODE_H
