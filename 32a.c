/*
========================================================================================================================================================================================
Name : 32a.c
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
#include <unistd.h>
#include <stdio.h>

union semun {
    int val;
};

int main()
{
    const char *ticketFile = "ticket-file.txt";
    int fd;
    int ticket;
    ssize_t n;

    fd = open(ticketFile, O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("File open error");
        return 1;
    }
    key_t key = ftok(".", 'A');
    int semid = semget(key, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget error");
        return 1;
    }

    union semun u;
    u.val = 1;
    semctl(semid, 0, SETVAL, u);//set the initial semaphore value.
    // Semaphore structure for P/V operations
    struct sembuf P = {0, -1, 0};  // wait
    struct sembuf V = {0,  1, 0};  // signal

    printf("Press ENTER to take the lock...\n");
    getchar();
    semop(semid, &P, 1);
    printf("LOCK acquired. Entering critical section...\n");
    n = read(fd, &ticket, sizeof(ticket));
    if (n <= 0) {
        ticket = 1;  // First ticket
    } else {
        ticket++;    // Increase ticket number
        lseek(fd, 0, SEEK_SET);   // Reset pointer to start
    }

   write(fd, &ticket, sizeof(ticket));
   printf("Your ticket number is : %d\n", ticket);
    printf("Press ENTER to release lock...\n");
    getchar();
    semop(semid, &V, 1);
    printf("LOCK released.\n");

    close(fd);
    return 0;
}

/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
Press ENTER to take the lock...

LOCK acquired. Entering critical section...
Your ticket number is : 4
Press ENTER to release lock...

LOCK released.
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ cc 32a.c
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
Press ENTER to take the lock...

LOCK acquired. Entering critical section...
Your ticket number is : 5
Press ENTER to release lock...

LOCK released.

*/
