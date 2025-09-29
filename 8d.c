/*
========================================================================================================================================================================================
Name : 8d.c
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
    printf("Caught SIGALRM\n");
}

int main() {
    signal(SIGALRM, handle);
    printf("trigger Alarm for 5 sec\n");
    alarm(5);
    pause();// wait for signal

    return 0;
}
/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
trigger Alarm for 5 sec
Caught SIGALRM


*/
