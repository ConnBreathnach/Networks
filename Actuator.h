//
// Created by conn on 01/10/2021.
//

#ifndef NETWORKS_ACTUATOR_H
#define NETWORKS_ACTUATOR_H


#include "Sender.h"
#include <cstdlib>
#include <time.h>
#include <string>

class Actuator : public Sender {
    Actuator();
    float generateNumber(int min, int max);
    void waitTime(int numSecs);
};


#endif //NETWORKS_ACTUATOR_H
