/*
========================================================================================================================================================================================
Name : 3.c
Author : Kartavyakumar Patel
Description : 3. Write a program to set (any one) system resource limit. Use setrlimit system call.
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

 l.rlim_cur=512; // change soft link 
 if(setrlimit(RLIMIT_NOFILE,&l)==0)
  printf("\nchanged file open cur limit:::\n");
 else
  {perror("setrlimit:: ");}
 
if(getrlimit(RLIMIT_NOFILE,&l)==0)
 {
 printf("\nfiles open soft(current):%ld\n",(long)l.rlim_cur);
 printf("files open Hard(MAXIMUM):%ld\n",(long)l.rlim_max);
 }
 
 return 0;
}
/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
files open soft(current):1024
files open Hard(MAXIMUM):1048576

changed file open cur limit:::

files open soft(current):512
files open Hard(MAXIMUM):1048576


*/
