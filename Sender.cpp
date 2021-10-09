//
// Created by conn on 01/10/2021.
//

#include "Sender.h"

void Sender::connectToSocket(sockaddr_in peer_addr)
{
    int connected_successfully = connect(socket_fd, (sockaddr*)&this->peer_addr, sizeof(this->peer_addr));
}

void Sender::sendPacket(char packet[])
{
    int message_send_successfully = send(socket_fd, packet, sizeof(packet), MSG_CONFIRM);
    if(message_send_successfully < 0) {
        printf("Error sending message");
    }
}