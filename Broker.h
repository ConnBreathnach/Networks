//
// Created by conn on 08/10/2021.
//

#ifndef NETWORKS_BROKER_H
#define NETWORKS_BROKER_H


#include "Receiver.h"
#include "Sender.h"
#include "Database.h"
#include <vector>

class Broker: public Sender, public Receiver {
    Database database;
    void processPayload();
    void processSubscriber(Header header, char* data);
    void processPublisher(Header header, char* data);
    std::vector<std::vector<sockaddr_in>> subscribers;

public:
    Broker();

    void processGatherer(Header header, char *data);

    void unsubscribe(Header header);

    void acknowledge(sockaddr_in addr);
};


#endif //NETWORKS_BROKER_H
