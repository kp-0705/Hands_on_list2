/*
========================================================================================================================================================================================
Name : 22.c
Author : Kartavyakumar Patel
Description : 22. Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.

Date : 18th sept, 2025
========================================================================================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
 int file_des;
 char para[500];
 mkfifo("FIFO_22",0666);
 file_des=open("FIFO_22",O_RDONLY | O_NONBLOCK);
 
 fd_set fd;
 FD_ZERO(&fd);
 FD_SET(file_des,&fd);
 
 struct timeval tv;
 tv.tv_sec=10;
 tv.tv_usec=0;
 int ans=select(file_des+1,&fd,NULL,NULL,&tv);
 
 if(ans>0 && FD_ISSET(file_des,&fd))
 {
   read(file_des,para,sizeof(para));
   printf("DATA:: %s\n",para);
 }
 else if(ans==0)
 {
 printf("NO DATA WRITTEN\n");
 }
 else
 {perror("SELECT ERR::");}
 close(file_des);
 return 0;
 
}

/*
 Output:
//if i wait for 10 sec so output is ......

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
NO DATA WRITTEN

// open second terminal and write something in fifo then output .....

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ echo "hello how are you?" > FIFO_22

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
DATA:: hello how are you?
*/
