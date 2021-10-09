//
// Created by conn on 21/09/2021.
//

#include "Client.h"

Client::Client()
{
    startClient();
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
    while(true)
    {
        cout << "Enter message to send to server!\n";
        cin >> buffer;
        int was_sent = send(socket_fd, buffer, sizeof(buffer), MSG_CONFIRM);
        if(was_sent == -1)
        {
            printf("Error sending message\n");
            exit(1);
        }
        else
        {
            printf("%d bytes sent\n", was_sent);
        }
        if(recvfrom(socket_fd, (char *)buffer, sizeof(buffer), MSG_WAITALL,(sockaddr *)&address, (socklen_t*)sizeof(address)) < 0);
    }

}
