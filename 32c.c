/*
========================================================================================================================================================================================
Name : 32c.c
Author : Kartavyakumar Patel
Description : 32. Write a program to implement semaphore to protect any critical section.
              a. rewrite the ticket number creation program using semaphore
              b. protect shared memory from concurrent write access
              c. protect multiple pseudo resources ( may be two) using counting semaphore
              d. remove the created semaphore

Date : 23th sept, 2025
========================================================================================================================================================================================
*/

#include <sys/ipc.h>   
#include <sys/sem.h>   
#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>     
#include<stdlib.h>
#include <unistd.h>    
#include <stdio.h>   

void main()
{
    char *filename = "file.txt"; 

    int fileDescriptor;           
    ssize_t readBytes; 
    off_t lseekOffset;
    char data[1000]; 

    key_t semKey;     
    int semIdentifier; 
    int semctlStatus;  
    int semopStatus;   

    
    fileDescriptor = open(filename, O_RDONLY);
    if (fileDescriptor == -1)
    {
        perror("Error!");
        exit(0);
    }

    union semun
    {
        int val;               
    } semSet;

    semKey = ftok(".", 331);
    if (semKey == -1)
    {
        perror("Error while computing key!");
        exit(1);
    }
    semIdentifier = semget(semKey, 1, 0); 
    if (semIdentifier == -1)
    {
        semIdentifier = semget(semKey, 1, IPC_CREAT | 0700); // Create a new semaphore 
        if (semIdentifier == -1)
        {
            perror("Error while creating semaphore!");
            exit(1);
        }
        semSet.val = 2; // Set a counting semaphore
        semctlStatus = semctl(semIdentifier, 0, SETVAL, semSet);
        if (semctlStatus == -1)
        {
            perror("Error while initializing a binary sempahore!");
            exit(1);
        }
    }
    struct sembuf semOp; // Defines the operation on the semaphore
    semOp.sem_num = 0;
    semOp.sem_flg = IPC_NOWAIT;

    printf("Press enter to obtain lock for the critical section!\n");
    getchar();

    // Use semaphore to lock the critical section
    semOp.sem_op = -1;
    semopStatus = semop(semIdentifier, &semOp, 1);
    if (semopStatus == -1)
    {
        perror("Error semaphore!");
        exit(1);
    }

    printf("lock on CS!");

    printf("entering CS!");

    readBytes = read(fileDescriptor, &data, 1000);
    if (readBytes == -1)
    {
        perror("Error sample file!");
        exit(0);
    }
    else if (readBytes == 0) // Sample file has no data
        printf("No data exists!\n");
    else
        printf("Sample data: \n %s", data);

    printf("\n\nPress enter key to exit CS\n");
    getchar();

  
    semOp.sem_op = 1;
    semopStatus = semop(semIdentifier, &semOp, 1);
    if (semopStatus == -1)
    {
        perror("Error while semaphore!");
        exit(1);
    }

    close(fileDescriptor);
}
/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
Press enter to obtain lock for the critical section!

Obtained lock on critical section!Now entering critical section!Sample data: 
 hello i am file so data store in me....
����

Press enter key to exit critical section!



*/
