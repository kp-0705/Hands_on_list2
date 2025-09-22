/*
========================================================================================================================================================================================
Name : 27.c
Author : Kartavyakumar Patel
Description : 27. Write a program to receive messages from the message queue.
              a. with 0 as a flag
              b. with IPC_NOWAIT as a flag

Date : 19th sept, 2025
========================================================================================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
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

 if((mid=msgget(k,0666))==-1)
 {
 perror("MSGGET::");
 exit(1);
 }
 printf("Msg queue :: ID::%d\n",mid);
 
 if(msgrcv(mid,&me,sizeof(me.m_text),0,0)==-1)
 {
 perror("MSGRCV::");
 exit(1);
 }
  printf("Blocking receive:  %s\n", me.m_text);
  
if(msgrcv(mid,&me,sizeof(me.m_text),0,IPC_NOWAIT)==-1)
 {
   if(errno==ENOMSG)
   printf("No messages in queue\n");
   else
   perror("MSGRCV::");
 }
 else
  printf("Non_Blocking receive:  %s\n", me.m_text);
   
 return 0;
}

/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ gcc 26.c -o send
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ gcc 27.c -o rec
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./send
Msg queue :: KEY::39
Msg queue :: ID::4
ENTER  Msg To sENd
send to 27.c bro
Message sent to  queue.

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./rec
Msg queue :: KEY::39
Msg queue :: ID::4
Blocking receive:  send to 27.c bro

No messages in queue

*/
