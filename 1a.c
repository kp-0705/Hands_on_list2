/*
========================================================================================================================================================================================
Name : 1a.c      
Author : Kartavyakumar Patel
Description : 1. Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second
              a. ITIMER_REAL
             
              
Date : 11th sept, 2025
========================================================================================================================================================================================
*/
#include<stdio.h>
#include<signal.h>
#include<sys/time.h>
#include<unistd.h>
void myhandler(int s)
{
printf("EXPIRED!\n");
}
int main()
{
struct itimerval t;
signal(SIGALRM,myhandler);
t.it_value.tv_sec=10;
t.it_value.tv_usec=0;
t.it_interval.tv_sec=10;
t.it_interval.tv_usec=0;

setitimer(ITIMER_REAL,&t,NULL);

while(1)
{
pause();
}
return 0;
}


/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ cc 1a.c
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
EXPIRED!
 jba ' csac hcw b n schwq ' cwh wvishnu EXPIRED!
EXPIRED!
EXPIRED!
xdv  jc a yh dd cb poojan EXPIRED!
EXPIRED!


*/
