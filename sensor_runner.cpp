//
// Created by conn on 15/10/2021.
//

#include "Sensor.h"
#include "Sensor.cpp"
#include "Node.h"
#include "Node.cpp"
#include "Sender.h"
#include "Sender.cpp"
#include "Database.h"
#include "Database.cpp"
#include "Payload.h"
#include "Payload.cpp"
#include "Header.h"
#include "Header.cpp"
#include "time.h"
#include <iostream>

int main() {
    char type;
    int id;
    std::cout << "Enter Sensor type and id\n";
    std::cin >> type >> id;
    Sensor *sensor = new Sensor(type, id);
}
