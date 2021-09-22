//
// Created by conn on 22/09/2021.
//

#include "Sender.h"


void Sender::startServer()
{
    int socket_failed = setsockopt(socket_fd, IPPROTO_UDP, SO_REUSEADDR, (void*)1, sizeof(int));
    if(socket_failed)
    {
        perror("Socket options failed.");
        exit(1);
    }
    int bind_failed = bind(socket_fd, (sockaddr *)&address, sizeof(address));
    if(bind_failed != 0)
    {
        perror("Socket binding failed.");
        exit(1);
    }


}