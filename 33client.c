/*
========================================================================================================================================================================================
Name : 33s.c
Author : Kartavyakumar Patel
Description : 33. Write a program to communicate between two machines using socket.

Date : 24th sept, 2025
========================================================================================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    while(1)
    {
    	send(sock , hello , strlen(hello) , 0 );
	printf("Hello message sent\n");
	read(sock, buffer, 1024);
	printf("Message from server: %s\n", buffer);
    }
    return 0;
}

/*
 Output:
//sender.....
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./33s
Hello message sent

*/
