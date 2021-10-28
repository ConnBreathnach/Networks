//
// Created by conn on 01/10/2021.
//

#include "Sender.h"
#include <errno.h>
#include <cstring>

void Sender::connectToSocket(char* peer_ip_addr)
{
//    peer_addr.sin_addr = INADDR_ANY;
    address.sin_addr.s_addr = inet_addr(peer_ip_addr);
    printf("%s \n", peer_ip_addr);


    int connected_successfully = connect(socket_fd, (sockaddr*)&this->address, sizeof(this->address));
    if(connected_successfully != 0)
    {
        perror("Client socket connection failed.");
        exit(1);
    }
    printf("\n Connected successfully\n");
}

void Sender::sendPacket(char packet[])
{
    socklen_t peer_len = sizeof(this->address);
    int message_send_successfully = sendto(socket_fd, packet, sizeof(packet), MSG_CONFIRM, (sockaddr*)&this->address, peer_len);
    if(message_send_successfully < 0) {


        printf("The last error message is: %s\n", strerror(errno));

        printf("Error sending message\n");
    }
}