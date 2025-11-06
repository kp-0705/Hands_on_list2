/*
========================================================================================================================================================================================
Name : 32b.c
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
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

union semun {
    int val;
};

int main()
{    
    key_t shm_key = ftok(".", 'M');
    int shmid = shmget(shm_key, 100, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget error");
        return 1;
    }

    char *shared = (char *)shmat(shmid, NULL, 0);
    if (shared == (void *)-1) {
        perror("shmat error");
        return 1;
    }

    key_t sem_key = ftok(".", 'S');
    int semid = semget(sem_key, 1, IPC_CREAT | 0666);
    if (semid == -1) 
    {
        perror("semget error");
        return 1;
    }

    union semun u;
    u.val = 1;
    semctl(semid, 0, SETVAL, u);

    // Semaphore P and V operations
    struct sembuf P = {0, -1, 0};   // Lock
    struct sembuf V = {0,  1, 0};   // Unlock

    printf("Press ENTER to write to shared memory..\n");
    getchar();

    semop(semid, &P, 1);
    printf("LOCK && Writing ...\n");

    strcpy(shared, "data written");
    printf("Shared Memory Data: %s\n", shared);

    sleep(5);  // simulate slow write
    semop(semid, &V, 1);
    printf("LOCK released.\n");

    // Detach shared memory
    shmdt(shared);

    return 0;
}

/*
 Output:
 *****Terminal 1....
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
Press ENTER to write to shared memory..

LOCK && Writing ...
Shared Memory Data: data written
LOCK released.


 *****Terminal 2....
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
Press ENTER to write to shared memory..
sdj c
cnsk
LOCK && Writing ...
Shared Memory Data: data written
LOCK released.

*/
