//
// Created by conn on 06/10/2021.
//

#ifndef NETWORKS_PAYLOAD_H
#define NETWORKS_PAYLOAD_H
#define MAX_DATA_SIZE 64

#include "Header.h"


class Payload {

    char data_buffer[MAX_DATA_SIZE];
    bool loadData(char* data);

public:
    Header header;
    bool loadData(float data);
    char* payload;
    void setPayload();
    char* getPayload();
    char* getData();
    Header getHeader();
};


#endif //NETWORKS_PAYLOAD_H
