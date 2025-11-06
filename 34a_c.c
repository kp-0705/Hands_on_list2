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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main()
{
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert SERVER IP string to binary
    if (inet_pton(AF_INET, "SERVER_IP", &serv_addr.sin_addr) <= 0) {
        printf("Invalid address\n");
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return -1;
    }

    char *msg = "Hello Server, this is Client!";

    send(sock, msg, strlen(msg), 0);
    printf("Message sent to server.\n");

    // Receive reply
    read(sock, buffer, sizeof(buffer));
    printf("Received from server: %s\n", buffer);

    close(sock);
    return 0;
}

/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./ce
Hello message sent



*/
