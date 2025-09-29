/*
========================================================================================================================================================================================
Name : 2.c
Author : Kartavyakumar Patel
Description : 2. Write a program to print the system resource limits. Use getrlimit system call.
Date : 28th sept, 2025
========================================================================================================================================================================================
*/

#include<stdio.h>
#include<sys/resource.h>
int main()
{
 struct rlimit l;
 if(getrlimit(RLIMIT_NOFILE,&l)==0)
 {
 printf("files open soft(current):%ld\n",(long)l.rlim_cur);
 printf("files open Hard(MAXIMUM):%ld\n",(long)l.rlim_max);
 }
 if(getrlimit(RLIMIT_STACK,&l)==0)
 {
 printf("stack soft(current):%ld\n",(long)l.rlim_cur);
 printf("stack Hard(MAXIMUM):%ld\n",(long)l.rlim_max);
 }
 return 0;
}

/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
files open soft(current):1024
files open Hard(MAXIMUM):1048576
stack soft(current):8388608
stack Hard(MAXIMUM):-1


*/
