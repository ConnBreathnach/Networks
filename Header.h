//
// Created by conn on 06/10/2021.
//

#ifndef NETWORKS_HEADER_H
#define NETWORKS_HEADER_H
#include <stdio.h>

class Header {
public:
    char type; //Either 's' for subscriber (client) or 'p' for publisher (actuator)

    int topic; // Type of data from actuators send/wanted

    int id;
    int timeStamp; // which message number this is from actuators. Used for caching/database management
    Header();
    Header(char type, int topic, int id);
    void incrementTimestamp();
    char* convertToCharArray();
};


#endif //NETWORKS_HEADER_H
