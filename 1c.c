/*
========================================================================================================================================================================================
Name : 1c.c      
Author : Kartavyakumar Patel
Description : 1. Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second
              c. ITIMER_PROF
             
              
Date : 11th sept, 2025
========================================================================================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

// Handler for SIGPROF
void myhandler(int s)
{
    printf("ITIMER_PROF EXPIRED!\n");
}

int main()
{
    struct itimerval t;

    // Register signal handler for SIGPROF
    signal(SIGPROF, myhandler);

    t.it_value.tv_sec = 10;
    t.it_value.tv_usec = 0;
    t.it_interval.tv_sec = 10;
    t.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &t, NULL);

    while (1)
    {
        // some CPU work to keep the process busy
        //Do NOT optimize this variable. Its value may change at any time(volatile)
        for (volatile long i = 0; i < 50000000; i++);
    }

    return 0;
}


/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
1232
sdas
ITIMER_PROF EXPIRED!
ddas
sasdsd
hello 
anjs
 sjd
d sdjsaa
f ITIMER_PROF EXPIRED!
djd
^C
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$

*/
