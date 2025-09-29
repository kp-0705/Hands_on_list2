/*
========================================================================================================================================================================================
Name : 34a_c.c
Author : Kartavyakumar Patel
Description : 34. Write a program to create a concurrent server.
              a. use fork
              b. use pthread_create
              
Date : 25th sept, 2025
========================================================================================================================================================================================
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

// Thread function
void *communicate(void *arg) {
    int fd = *(int*)arg;
    free(arg); // free memory allocated for fd

    ssize_t readBytes, writeBytes;
    char dataFromClient[100] = {0};

    // Send message to client
    writeBytes = write(fd, "I'm the server!", 15);
    if (writeBytes == -1)
        perror("Error while writing to client");
    else
        printf("Data sent to client!\n");

    // Read message from client
    readBytes = read(fd, dataFromClient, sizeof(dataFromClient));
    if (readBytes == -1)
        perror("Error while reading from client");
    else
        printf("Data from client: %s\n", dataFromClient);

    close(fd);
    return NULL;
}

int main() {
    int socketFileDescriptor, connectionFileDescriptor;
    int bindStatus, listenStatus;
    socklen_t clientSize;

    struct sockaddr_in address, client;
    pthread_t threadID;

    // Create socket
    socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFileDescriptor == -1) {
        perror("Error while creating socket");
        exit(1);
    }
    printf("Server side socket successfully created!\n");

    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);

    // Bind
    bindStatus = bind(socketFileDescriptor, (struct sockaddr *)&address, sizeof(address));
    if (bindStatus == -1) {
        perror("Error while binding socket");
        exit(1);
    }
    printf("Binding successful!\n");

    // Listen
    listenStatus = listen(socketFileDescriptor, 5);
    if (listenStatus == -1) {
        perror("Error while listening");
        exit(1);
    }
    printf("Server listening on port 8080...\n");

    // Accept multiple clients
    while (1) {
        clientSize = sizeof(client);
        connectionFileDescriptor = accept(socketFileDescriptor, (struct sockaddr *)&client, &clientSize);
        if (connectionFileDescriptor == -1) {
            perror("Error while accepting connection");
            continue;
        }

        int *fdPtr = malloc(sizeof(int));
        *fdPtr = connectionFileDescriptor;

        if (pthread_create(&threadID, NULL, communicate, fdPtr) != 0) {
            perror("Error while creating thread");
            close(connectionFileDescriptor);
            free(fdPtr);
        } else {
            pthread_detach(threadID); // auto-clean thread
        }
    }

    close(socketFileDescriptor);
    return 0;
}

/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./34c
Server side socket successfully created!
Binding successful!
Server listening on port 8080...


*/
