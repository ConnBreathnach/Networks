//
// Created by conn on 01/10/2021.
//

#ifndef NETWORKS_SENSOR_H
#define NETWORKS_SENSOR_H


#include "Sender.h"
#include <cstdlib>
#include <time.h>
#include <string>

class Sensor : public Sender {
    float generateNumber(int min, int max);
    void waitTime(int numSecs);

public:
    Sensor();
};


#endif //NETWORKS_SENSOR_H
