/*
========================================================================================================================================================================================
Name : 8b.c
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
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handle(int sig) {
    printf("Caught SIGINT (Ctrl+C)\n");
    exit(0);
}

int main() {
    signal(SIGINT, handle);
    printf("trigger SIGINT...\n");

    while(1)
    {sleep(1);}
    
    return 0;
}

/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
trigger SIGINT...
^CCaught SIGINT (Ctrl+C)

*/
