//
// Created by conn on 08/10/2021.
//

#ifndef NETWORKS_BROKER_H
#define NETWORKS_BROKER_H


#include "Receiver.h"
#include "Sender.h"
#include "Database.h"

class Broker: public Receiver, public Sender {
    Broker();
    Database database;
    void processPayload();

};


#endif //NETWORKS_BROKER_H
