//
// Created by conn on 06/10/2021.
//

#include "Payload.h"

Payload::Payload() {}

bool Payload::loadData(char *data) {
    snprintf(this->data_buffer, MAX_DATA_SIZE, "%c", data); // Loads data into data buffer
}

bool Payload::loadData(float data) {
    snprintf(this->data_buffer, MAX_DATA_SIZE, "%f", data); // Loads data into data buffer
}



void Payload::setPayload() {
    char* header = this->header.convertToCharArray();
    this->header.incrementTimestamp();
    sprintf(this->payload, "%s%s", header, this->data_buffer);
}

char* Payload::getPayload() {
    return this->payload;
}

Header Payload::getHeader(){
    return this->header;
}

char* Payload::getData() {
    return this->data_buffer;
}