//
// Created by conn on 08/10/2021.
//

#ifndef NETWORKS_RECEIVER_H
#define NETWORKS_RECEIVER_H
#include "Node.h"

class Receiver: virtual public Node {
public:
    char *connectedMessage = "Server received message";
    Receiver();
    void setOptions();
    void bind();
    void listen();
};


#endif //NETWORKS_RECEIVER_H
