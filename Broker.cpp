//
// Created by conn on 08/10/2021.
//

#include "Broker.h"


Broker::Broker(){
}



void Broker::processPayload() {
    Header header = payload.getHeader();
    char* data = payload.getData();
    switch(header.type) {
        case('s'):
            processSubscriber(header, data);
            break;
        case('p'):
            processPublisher(header, data);
            break;
        case('g'):
            processGatherer(header, data);
            break;
        case('u'):
            break;
        case('a'):
            break;
        default:
            printf("Header type invalid");
            break;
    }
}

void Broker::processSubscriber(Header header, char *data) {
    int topic = header.topic;
    
}

void Broker::processPublisher(Header header, char *data) {
    //Topic - 0 is heat, 1 is mass
    int topic = header.topic;
    int id = header.id;
    int timestamp = header.timeStamp;
    float newData = atof(data);
    switch (topic) {
        case 1:
            database.saveHeatData(newData, id, timestamp);
            break;
        case 2:
            database.saveMassData(newData, id, timestamp);
            break;
        default:
            printf("Error with topic. Possibly out of range");
            break;
    }
}

void Broker::processGatherer(Header header, char *data) {
    int topic = header.topic;
    int id = header.id; // Id of subscrber to send data to

    struct sockaddr_in cliaddr;
    socklen_t len = sizeof(cliaddr);
    float sendData;
    switch (topic) {
        case 1: {
            sendData = database.getHeat(id);
            break;
            }
        case 2: {
            sendData = database.getMass(id);
            break;
        }
        case 3: {
            float* sendData = database.getHeatAndMass(id);
            break;
        }
        default:
            float sendData = 0;
            printf("Gatherer topic error.");
            break;
    }
    sendto(socket_fd, &sendData, sizeof(sendData), MSG_CONFIRM, (sockaddr *)&cliaddr, sizeof(cliaddr));
}

