//
// Created by conn on 21/09/2021.
//

#ifndef NETWORKS_CLIENT_H
#define NETWORKS_CLIENT_H

#include "Sender.h"
#include "Receiver.h"
#include <iostream>
using namespace std;
class Client: public Sender, public Receiver {
public:
    Client();
    void startClient();
    char* createMessage();
    
};


#endif //NETWORKS_CLIENT_H
