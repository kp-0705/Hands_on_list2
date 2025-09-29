/*
========================================================================================================================================================================================
Name : 6.c
Author : Kartavyakumar Patel
Description : 6. Write a simple program to create three threads.

Date : 28th sept, 2025
========================================================================================================================================================================================
*/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* make_thread(void* arg)
{
  int num=*((int*)arg);
  printf("thread num %d\n",num);
}
int main()
{
    pthread_t threads[5];
    int ids[5];
    for(int i=0;i<5;i++)
    {
    ids[i]=i+1;
    if(pthread_create(&threads[i],NULL,make_thread,&ids[i])!=0)
    {perror("Failed.....::");}
    }
    for(int i=0;i<5;i++)
    {
    pthread_join(threads[i],NULL);
    }
    return 0;
}

/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
thread num 1
thread num 2
thread num 4
thread num 3
thread num 5

*/
