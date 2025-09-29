/*
========================================================================================================================================================================================
Name : 4.c
Author : Kartavyakumar Patel
Description : 4. Write a program to measure how much time is taken to execute 100 getppid ( ) system call. Use time stamp counter.

Date : 28th sept, 2025
========================================================================================================================================================================================
*/
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main()
{
struct timeval s,e;
long time;
gettimeofday(&s,NULL);

for(int i=0;i<100;i++)
{
 getppid();
}
gettimeofday(&e,NULL);
time=(e.tv_sec - s.tv_sec)*1000000L+(e.tv_usec - s.tv_usec);

printf("total Time(micro_sec):: %ld\n",time);
return 0;
}
/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
total Time(micro_sec):: 52


*/
