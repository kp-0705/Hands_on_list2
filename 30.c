/*
========================================================================================================================================================================================
Name : 30.c
Author : Kartavyakumar Patel
Description : 30. Write a program to create a shared memory.
              a. write some data to the shared memory
              b. attach with O_RDONLY and check whether you are able to overwrite.
              c. detach the shared memory
              d. remove the shared memory

Date : 19th sept, 2025
========================================================================================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int  main()
{
 key_t key;
 int sid;
 char *shmadd;
 
 if((key=ftok(".",'S'))==-1)
 {  perror("ftok");
        exit(1);
 }
 if((sid=shmget(key,1024,IPC_CREAT| 0666))==-1)
 {
     perror("shmget");
     exit(1);
 }
 shmadd = shmat(sid, NULL, 0);
  if (shmadd == (char *)-1) {
        perror("shmat");
        exit(1);
    }

 strncpy(shmadd,"HEllo,I AM share Memory::",1024);
 
 printf("Data write in shared memory:: %s\n",shmadd);
 shmadd= shmat(sid, NULL,SHM_RDONLY);
 if (shmadd == (char *)-1)
{       perror("shmat");
        exit(1);
    }
    
   if(shmdt(shmadd)==-1) 
   {  perror("shmdt");
        exit(1);
   }
   if (shmctl(sid, IPC_RMID, NULL) == -1) 
   {
        perror("shmctl");
        exit(1);
    } 
   printf("Shared memory removed.\n");
   return 0;
}


/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
Data write in shared memory:: HEllo,I AM share Memory::
Shared memory removed.

*/
