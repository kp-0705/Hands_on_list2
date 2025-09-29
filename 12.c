/*
========================================================================================================================================================================================
Name : 12.c
Author : Kartavyakumar Patel
Description : 12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to the parent process from the child process.

Date : 29th sept, 2025
========================================================================================================================================================================================
*/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
 if(!fork())
 {
  printf("CHILD ID: %d , PARENT of CHILD: %d\n",getpid(),getppid());
  kill(getppid(),SIGKILL);
  printf("\nNOW ORPHAN PROCESS BCZ child killed parent\n");
  sleep(5);
  printf("CHILD NEW PARENT PID::%d\n",getppid());
 
 }
 else
 {
  printf("PARENT ID: %d\n",getpid());
  sleep(5);//kepp alive for a moment
  printf("parent process terminate.....\n");
 }
 return 0;
}

/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
PARENT ID: 15638
CHILD ID: 15639 , PARENT of CHILD: 15638

NOW ORPHAN PROCESS BCZ child killed parent
Killed
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ CHILD NEW PARENT PID::1948  //wait for 5 sec 


*/
