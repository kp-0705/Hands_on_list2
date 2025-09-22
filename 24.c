/*
========================================================================================================================================================================================
Name : 24.c
Author : Kartavyakumar Patel
Description : 24. Write a program to create a message queue and print the key and message queue id.

Date : 18th sept, 2025
========================================================================================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
 key_t k;
 int mid;
 k=ftok(".",'A');
 if(k==-1)// generate unique key for mesgqueue...
 {
  perror("MSGQUEUE::");
  exit(1);
 }
 printf("Msg queue :: key:: %d\n",k);
 if((mid=msgget(k,IPC_CREAT|0666))==-1)
 {
 perror("MSGGET::");
 exit(1);
 }
 printf("Msg queue :: ID::%d\n",mid);
 return 0;
}

/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
Msg queue :: key:: 1090862964
Msg queue :: ID::0
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x41053f74 0          dell       666        0            0           

*/
