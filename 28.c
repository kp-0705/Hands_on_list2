/*
========================================================================================================================================================================================
Name : 28.c
Author : Kartavyakumar Patel
Description : 28. Write a program to change the exiting message queue permission. (use msqid_ds structure)
Date : 19th sept, 2025
========================================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main()
{
 key_t k=0x00000027;
 int mid;
 struct msqid_ds q_info;
 
 if((mid=msgget(k,0666))==-1)
 {
  perror("MSGGET");
  exit(1);
 }
 
 if(msgctl(mid,IPC_STAT,&q_info)==-1)
  {
  perror("MSGGET");
  exit(1);
  }
 printf("Msg_queue:: ID:: %d\n",mid);
 
 q_info.msg_perm.mode=0644;
 
 if(msgctl(mid,IPC_SET,&q_info)==-1)
  {
  perror("MSGGET");
  exit(1);
  }
printf("Permission change.\n");
return 0;
}

/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x00000027 0          dell       666        0            0           

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ cc 28.c
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
Msg_queue:: ID:: 0
Permission change.
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x00000027 0          dell       644        0            0         
*/
