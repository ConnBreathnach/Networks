//
// Created by conn on 22/09/2021.
//

#include "Server.h"
#include <unistd.h>

void Server::startServer()
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

    int listen_failed = listen(socket_fd, 10); //Backlog is 10, could probably be shorter but I'm happy
    if(listen_failed != 0)
    {
        perror("Listening failed");
        exit(1);
    }

    //Server is now bound and listening, run loop forever
    while(true)
    {
        int clientSocket = accept(socket_fd, (sockaddr *)&address, (socklen_t*)sizeof(address));
        if(clientSocket != -1)
        {
            int was_read = read(clientSocket, buffer, sizeof(buffer));
            printf("Received message: %s \n", buffer);
            send(clientSocket, connectedMessage, sizeof(connectedMessage), MSG_CONFIRM);
        }
    }
}

int Server::main()
{
    startServer();
    return 0;
}