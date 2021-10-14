//
// Created by conn on 08/10/2021.
//

#include "Database.h"

void Database::saveHeatData(float heat, int actuatorId, int timestamp) {
    if(heatTimestamps.at(actuatorId) < timestamp) {
        this->heatData.at(actuatorId) = heat;
        this->heatTimestamps.at(actuatorId) = timestamp;
    }
}

void Database::saveMassData(float mass, int actuatorId, int timestamp) {
    if(massTimestamps.at(actuatorId) < timestamp)
    {
        this->massData.at(actuatorId) = mass;
        this->massTimestamps.at(actuatorId) = timestamp;
    }
}

float Database::getHeat(int id) {
    return this->heatData.at(id);
}

float Database::getMass(int id) {
    return this->massData.at(id);
}

float* Database::getHeatAndMass(int id) {
    float heatAndMass[] = {getHeat(id), getMass(id)};
    return heatAndMass;
}

//float* Database::getHeats(int ids[]) {
//    float heats[] = new float[ids.length];
//}

