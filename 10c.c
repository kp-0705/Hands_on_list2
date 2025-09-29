/*
========================================================================================================================================================================================
Name : 10c.c
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
printf("Caught SIGFPE FLoating point.....\n");
exit(1);
}

int main()
{
struct sigaction sig;
sig.sa_handler=handle;
sigemptyset(&sig.sa_mask);
sig.sa_flags=0;

sigaction(SIGFPE,&sig,NULL);
printf("triggering divide by zero or Integer overflow or Modulo by zero....\n");
int a=0;
int b=1;
int c=b/a;
printf("Answer:: %d",c);

return 0;
}
/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
triggering divide by zero or Integer overflow or Modulo by zero....
Caught SIGFPE FLoating point.....


*/
