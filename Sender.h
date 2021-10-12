//
// Created by conn on 01/10/2021.
//

#ifndef NETWORKS_SENDER_H
#define NETWORKS_SENDER_H


#include "Node.h"

class Sender : virtual public Node {
public:
    struct sockaddr_in peer_addr;
    void connectToSocket(sockaddr_in peer_addr);
    void sendPacket(char packet[]);
};


#endif //NETWORKS_SENDER_H
