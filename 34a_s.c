/*
========================================================================================================================================================================================
Name : 34a_s.c
Author : Kartavyakumar Patel
Description : 34. Write a program to create a concurrent server.
              a. use fork
              b. use pthread_create
              
Date : 25th sept, 2025
========================================================================================================================================================================================
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(1);
    }

    // Server address setup
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;   // Accept from any IP
    address.sin_port = htons(PORT);

    // Bind socket to port
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for client
    listen(server_fd, 3);
    printf("Server waiting for connection...\n");

    // Accept connection
    new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
    if (new_socket < 0) {
        perror("accept");
        exit(1);
    }

    // Read message
    read(new_socket, buffer, sizeof(buffer));
    printf("Received from client: %s\n", buffer);

    // Reply to client
    char *msg = "Message received by server!";
    send(new_socket, msg, strlen(msg), 0);

    close(new_socket);
    close(server_fd);
    return 0;
}

/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./se
Message from client: Hello from client




*/
