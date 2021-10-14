//
// Created by conn on 08/10/2021.
//

#include "Receiver.h"
Receiver::Receiver()
{
    printf("Server ip address: %s \n", inet_ntoa(address.sin_addr));
    setOptions();
    bind();
    listen();
}

void Receiver::setOptions() {
    int opt = 1;
    int socket_failed = setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
    if(socket_failed)
    {
        perror("Server socket options failed.");
        exit(1);
    }
    printf("Server socket options set\n");
}


void Receiver::bind() {
    int bind_failed = ::bind(socket_fd, (sockaddr *)&address, sizeof(address));
    if(bind_failed != 0)
    {
        perror("Socket binding failed.");
        exit(1);
    }
    printf("Server bound\n");
}

void Receiver::listen() {
        struct sockaddr_in cliaddr;
        socklen_t len = sizeof(cliaddr);
        int was_received = recvfrom(socket_fd, payload.payload, sizeof(payload.payload), MSG_WAITALL, (struct sockaddr *) &cliaddr, &len);

        if (was_received < 0) {
            perror("Error receiving message");
        } else {
            // int was_read = read(clientSocket, buffer, sizeof(buffer));
            printf("Received message: %d \n", sizeof(payload.payload));
            sendto(socket_fd, connectedMessage, sizeof(connectedMessage), MSG_CONFIRM, (sockaddr *) &cliaddr,
                   sizeof(cliaddr));
    }
}