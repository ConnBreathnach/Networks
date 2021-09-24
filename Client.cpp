//
// Created by conn on 21/09/2021.
//

#include "Client.h"

void Client::startClient()
{
    int connectFailed = connect(socket_fd, (sockaddr *)&address, sizeof(address));
    if(connectFailed != 0)
    {
        perror("Client socket connection failed.");
        exit(1);
    }
    while(true)
    {
        cout << "Enter message to send to server!";
        cin >> buffer;
        send(socket_fd, buffer, sizeof(buffer), MSG_CONFIRM);
    }

}