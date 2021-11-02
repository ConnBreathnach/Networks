//
// Created by conn on 14/10/2021.
//

#include "Broker.h"
#include "Broker.cpp"
#include "Node.h"
#include "Node.cpp"
#include "Receiver.h"
#include "Receiver.cpp"
#include "Sender.cpp"
#include "Database.h"
#include "Database.cpp"
#include "Payload.h"
#include "Payload.cpp"
#include "Header.h"
#include "Header.cpp"
int main() {
    Broker *broker = new Broker();
    while (true){
        broker->processPayload();
    }
}