/*
========================================================================================================================================================================================
Name : 10b.c
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
printf("Caught SIGINT\n");
}

int main()
{
struct sigaction sig;
sig.sa_handler=handle;
sigemptyset(&sig.sa_mask);
sig.sa_flags=0;

sigaction(SIGINT,&sig,NULL);
printf("triggering SIGINT..\n");
while(1)
{
printf("Running...\n");
sleep(5);
}
return 0;
}
/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
triggering SIGINT..
Running...
^CCaught SIGINT
Running...
^CCaught SIGINT
Running...
^CCaught SIGINT
Running...
Running...
^CCaught SIGINT
Running...
Running...
^CCaught SIGINT
Running...
^CCaught SIGINT
Running...
Running...
Running...
Running...
^Z
[1]+  Stopped                 ./a.out


*/
