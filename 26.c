/*
========================================================================================================================================================================================
Name : 26.c
Author : Kartavyakumar Patel
Description : 26. Write a program to send messages to the message queue. Check $ipcs -q

Date : th sept, 2025
========================================================================================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


struct msg_buf{
    long m_type;
    char m_text[256];
};
int main()
{
 key_t k=39;
 int mid;
 struct msg_buf me;
 
printf("Msg queue :: KEY::%d\n",k);
 if((mid=msgget(k,IPC_CREAT|0666))==-1)
 {
 perror("MSGGET::");
 exit(1);
 }
 printf("Msg queue :: ID::%d\n",mid);
printf("ENTER  Msg To sENd\n");
fgets(me.m_text,sizeof(me.m_text),stdin);
me.m_type=1;

if(msgsnd(mid,&me,sizeof(me.m_text),0)==-1)
{
 perror("MSGSND::");
 exit(1);
}
printf("Message sent to  queue.\n");

 return 0;
}

/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
Msg queue :: KEY::36
Msg queue :: ID::2
ENTER  Msg To sENd
hello i am msgqueue
Message sent to  queue.
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x41053f74 0          dell       666        0            0           
0x42053f74 1          dell       666        0            0           
0x00000024 2          dell       666        264          1           


//0x00000024 = 36 in decimal
*/
