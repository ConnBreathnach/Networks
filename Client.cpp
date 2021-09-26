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
    int connectFailed = connect(socket_fd, (sockaddr *)&address, sizeof(address));
    if(connectFailed != 0)
    {
        perror("Client socket connection failed.");
        exit(1);
    }
    printf("Client connected\n");
    // while(true)
    // {
        // cout << "Enter message to send to server!\n";
        // cin >> buffer;
        // printf("%s \n", buffer);
        buffer[0] = 'a';
        buffer[1] = 'b';
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
    // }

}
