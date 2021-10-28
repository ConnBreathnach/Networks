//
// Created by conn on 06/10/2021.
//

#include "Header.h"
Header::Header() {}

Header::Header(char type, char topic, int id) {
    this->type = type;
    this->topic = topic;
    this->id = id;
    this->timeStamp = 0;
}

void Header::incrementTimestamp() {
    this->timeStamp++;
}

char* Header::convertToCharArray() {
    int headerSize = sizeof(this->type) + sizeof(this->topic) + sizeof(this->id) + sizeof(this->type);
    char header[headerSize];
    sprintf(header, "%c%d%d%d", this->type, this->topic, this->id, this->timeStamp);
    return header;
}