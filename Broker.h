//
// Created by conn on 08/10/2021.
//

#ifndef NETWORKS_BROKER_H
#define NETWORKS_BROKER_H


#include "Receiver.h"
#include "Sender.h"
#include "Database.h"

class Broker: public Receiver, public Sender {
    Database database;
    void processPayload();
    void processSubscriber(Header header, char* data);
    void processPublisher(Header header, char* data);


public:
    Broker();
};


#endif //NETWORKS_BROKER_H
