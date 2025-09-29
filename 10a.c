/*
========================================================================================================================================================================================
Name : 10a.c
Author : Kartavyakumar Patel
Description : 10. Write a separate program using sigaction system call to catch the following signals.
              a. SIGSEGV
              b. SIGINT
              c. SIGFPE 

Date : 29th sept, 2025
========================================================================================================================================================================================
*/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void handle(int seg)
{
printf("Caught segment fault\n");
exit(1);
}

int main()
{
struct sigaction sig;
sig.sa_handler=handle;
sigemptyset(&sig.sa_mask);
sig.sa_flags=0;

sigaction(SIGSEGV,&sig,NULL);
printf("triggering seg_fault..\n");
int *p=NULL;
*p=10;   //invalid in user-space.

return 0;
}
/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
triggering seg_fault..
Caught segment fault


*/
