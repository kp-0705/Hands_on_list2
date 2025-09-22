/*
========================================================================================================================================================================================
Name : 25.c
Author : Kartavyakumar Patel
Description : 25. Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
              a. access permission
              b. uid, gid
              c. time of last message sent and received
              d. time of last change in the message queue
              e. size of the queue
              f. number of messages in the queue
              g. maximum number of bytes allowed
              h. pid of the msgsnd and msgrcv

Date : 19th sept, 2025
========================================================================================================================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<time.h>

int main()
{
 key_t k;
 int mid;
 struct msqid_ds q_info;
 k=ftok(".",'B');
 if(k==-1)// generate unique key for mesgqueue...
 {
  perror("MSGQUEUE::");
  exit(1);
 }
 //printf("Msg queue :: key:: %d\n",k);
 if((mid=msgget(k,IPC_CREAT|0666))==-1)
 {
 perror("MSGGET::");
 exit(1);
 }
 //printf("Msg queue :: ID::%d\n",mid);
 // Get the message queue ID associated with the key
 if((mid=msgget(k,0666))==-1)
 {
 perror("MSGGET::");
 exit(1);
 }
 // Get info about the message queue
 if(msgctl(mid,IPC_STAT,&q_info)==-1)
 {
  perror("MSGCTL::");
 exit(1);
 }
 printf("a. Access permission : %o\n",q_info.msg_perm.mode);
	printf("b. UID: %d\n", q_info.msg_perm.uid);
	printf("   GID: %d\n", q_info.msg_perm.gid);
	printf("c. Time of last message sent: %s", ctime(&q_info.msg_stime));
	printf("   Time of last message received: %s", ctime(&q_info.msg_rtime));
	printf("d. Time of last change: %s", ctime(&q_info.msg_ctime));
	printf("e. Size of the queue: %lu bytes\n", (unsigned long)q_info.msg_qbytes);
	printf("f. Number of messages in the queue: %lu\n", (unsigned long)q_info.msg_qnum);
	printf("g. Maximum number of bytes allowed: %lu bytes\n", (unsigned long)q_info.msg_qbytes);
	printf("h. PID of msgsnd: %d\n", q_info.msg_lspid);
	printf("   PID of msgrcv: %d\n", q_info.msg_lrpid);
	
 return 0;
}


/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
a. Access permission : 666
b. UID: 1000
   GID: 1000
c. Time of last message sent: Thu Jan  1 05:30:00 1970
   Time of last message received: Thu Jan  1 05:30:00 1970
d. Time of last change: Sat Sep 20 22:59:30 2025
e. Size of the queue: 16384 bytes
f. Number of messages in the queue: 0
g. Maximum number of bytes allowed: 16384 bytes
h. PID of msgsnd: 0
   PID of msgrcv: 0

*/
