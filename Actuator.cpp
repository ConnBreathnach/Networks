//
// Created by conn on 01/10/2021.
//

#include "Actuator.h"

Actuator::Actuator() {
    connectToSocket("172.20.0.2");
    while(true) {

        printf("Sending data");
        waitTime(1);
        float randomTemp = generateNumber(16, 27);
        printf("Temp: %f \n", randomTemp);
        this->payload.loadData(randomTemp);
        sendPacket(this->payload.getPayload());
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