//
// Created by conn on 08/10/2021.
//

#ifndef NETWORKS_DATABASE_H
#define NETWORKS_DATABASE_H

#include <vector>

class Database {
    std::vector<float> heatData;
    std::vector<int> heatTimestamps;
    std::vector<float> massData;
    std::vector<int> massTimestamps;
    void saveHeatData(float heat, int actuatorId);
    void saveMassData(float mass, int actuatorId);
    float getHeat(int id);
    float getMass(int id);
    float* getHeatAndMass(int id);
    float* getHeats(int ids[]);
    float* getMasses(int ids[]);

};


#endif //NETWORKS_DATABASE_H
