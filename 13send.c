/*
========================================================================================================================================================================================
Name : 13send.c
Author : Kartavyakumar Patel
Description : 13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call). 
              Find out whetherthe first program is able to catch the signal or not.
            
Date : 29th sept, 2025
========================================================================================================================================================================================
*/
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
 if(argc!=2)
 {
  printf("USE only %s pid \n",argv[0]);
  exit(1);
  }
pid_t id=atoi(argv[1]); //converts a string argument into an integer
if(kill(id,SIGSTOP)==-1)
{
 perror("KILL::  ");
 return 1;
}
printf("Sent SIGSTOP to Process %d\n",id);

return 0;
}
/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./send 15828
Sent SIGSTOP to Process 15828


*/
