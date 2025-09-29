/*
========================================================================================================================================================================================
Name : 8a.c
Author : Kartavyakumar Patel
Description : 8. Write a separate program using signal system call to catch the following signals.
              a. SIGSEGV
              b. SIGINT
              c. SIGFPE
              d. SIGALRM (use alarm system call)
              e. SIGALRM (use setitimer system call)
              f. SIGVTALRM (use setitimer system call)
              g. SIGPROF (use setitimer system call)

Date : 28th sept, 2025
========================================================================================================================================================================================
*/
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void handle(int seg)
{
printf("Caught segment fault\n");
exit(1);
}

int main()
{
signal(SIGSEGV,handle);
printf("up sigsegv..\n");
int *p=NULL;
*p=10;   //invalid in user-space.

return 0;
}


/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
up sigsegv..
Caught segment fault


*/
