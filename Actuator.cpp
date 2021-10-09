//
// Created by conn on 01/10/2021.
//

#include "Actuator.h"

Actuator::Actuator() {
    connectToSocket();
    while(true) {
        waitTime(5);
        float randomTemp = generateNumber(16, 27);
        this->payload.loadData(randomTemp);
    }
}

float Actuator::generateNumber(int min, int max) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = max - min;
    float r = random * diff;
    return min + r;
}

void Actuator::waitTime(int waitSecs) {
    float timeDelta = 0;
    clock_t clk = clock(), temp;

    while (timeDelta <= waitSecs) {
        temp = clock() - clk;
        clk = clock();
        timeDelta += (float) ((float) temp / CLOCKS_PER_SEC);
    }
}