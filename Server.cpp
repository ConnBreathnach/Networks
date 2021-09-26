//
// Created by conn on 22/09/2021.
//

#include "Server.h"
#include <unistd.h>

Server::Server()
{
    startServer();
}

void Server::startServer()
{
    int opt = 1;
    int socket_failed = setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
    if(socket_failed)
    {
        perror("Server socket options failed.");
        exit(1);
    }
    printf("Server socket options set\n");
    int bind_failed = bind(socket_fd, (sockaddr *)&address, sizeof(address));
    if(bind_failed != 0)
    {
        perror("Socket binding failed.");
        exit(1);
    }
    printf("Server bound\n");

    // int listen_failed = listen(socket_fd, 10); //Backlog is 10, could probably be shorter but I'm happy
    // if(listen_failed != 0)
    // {
    //     perror("Listening failed");
    //     exit(1);
    // }

    //Server is now bound and listening, run loop forever
    while(true)
    {
        int was_received = recvfrom(socket_fd, buffer, sizeof(buffer), 0,(sockaddr *)&address, (socklen_t*)sizeof(address));
        if(was_received > -1)
        {
            // int was_read = read(clientSocket, buffer, sizeof(buffer));
            printf("Received message: %s \n", buffer);
            send(socket_fd, connectedMessage, sizeof(connectedMessage), MSG_CONFIRM);
        }
    }
}

