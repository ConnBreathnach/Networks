//
// Created by conn on 21/09/2021.
//

#include "Client.h"

Client::Client()
{
    startClient();
}

char* Client::createMessage() {
    char topic, type;
    int id;
    cout << "Enter message to send to server, in the format topic type id where topic is s/g for subscriber or gatherer, and type and id are integers.\n";
    cin >> topic >> type >> id;
    this->payload.header = new Header(topic, type, id);
    this->payload.setPayload();
    return this->payload.getPayload();
}

void Client::startClient()
{
    address.sin_addr.s_addr = inet_addr("172.20.0.2");

//    address.sin_port = htons(12345);
    printf("Client address: %s \n", inet_ntoa(address.sin_addr));
    int connectFailed = connect(socket_fd, (sockaddr *)&address, sizeof(address));
    if(connectFailed != 0)
    {
        perror("Client socket connection failed.");
        exit(1);
    }
    printf("Client connected\n");
    while(true) {
        char *buffer = createMessage();

        int was_sent = send(socket_fd, buffer, sizeof(buffer), MSG_CONFIRM);
        if (was_sent == -1) {
            printf("Error sending message\n");
            exit(1);
        } else {
            printf("%d bytes sent\n", was_sent);
        }
        char* dataReceived;
        int response = recvfrom(socket_fd, dataReceived, sizeof(dataReceived), MSG_WAITALL, (sockaddr *) &address,(socklen_t *) sizeof(address)) < 0;
        printf("Data from sensor: %s \n", dataReceived);
    }

}
