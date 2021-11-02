//
// Created by conn on 21/09/2021.
//

#include "Node.h"

Node::Node(int port_number)
{
    this->port_number = port_number;
    address.sin_port = htons(port_number);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;

    socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(socket_fd <= 0) //failed
    {
        perror("Socket creating failed.");
        exit(1);
    }

}


