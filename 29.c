/*
========================================================================================================================================================================================
Name : 29.c
Author : Kartavyakumar Patel
Description : 29. Write a program to remove the message queue.

Date : 22th sept, 2025
========================================================================================================================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
int main()
{
key_t k=(key_t)'K';
int mid;
if((mid=msgget(k,IPC_CREAT|0666))==-1)
{
  perror("msgget");
  exit(1);
}
if(msgctl(mid,IPC_RMID,NULL)==-1)
{
perror("msgctl");
        exit(1);
}
 printf("Mes_que removed.\n");
}

/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
Mes_que removed.

*/
