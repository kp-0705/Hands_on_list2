/*
========================================================================================================================================================================================
Name : 8f.c
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
#include<sys/time.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handle(int sig) {
    printf("Caught SIGVTALRM(virtual time..)\n");
}

int main() {
    signal(SIGVTALRM, handle);
    printf("trigger SIGINT...\n");
    struct itimerval t;
    t.it_value.tv_sec=1;
    t.it_value.tv_usec=0;
    t.it_interval.tv_sec=1;
    t.it_interval.tv_usec=0;
    setitimer(ITIMER_VIRTUAL,&t,NULL);
    
    while(1){}
    
    return 0;
}
/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
trigger SIGINT...
Caught SIGVTALRM(virtual time..)
Caught SIGVTALRM(virtual time..)
Caught SIGVTALRM(virtual time..)
Caught SIGVTALRM(virtual time..)
Caught SIGVTALRM(virtual time..)
^C


*/
