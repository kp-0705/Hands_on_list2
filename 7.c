/*
========================================================================================================================================================================================
Name : 7.c
Author : Kartavyakumar Patel
Description : 7. Write a simple program to print the created thread ids.

Date : 28th sept, 2025
========================================================================================================================================================================================
*/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* make_thread(void* arg)
{
  int num=*((int*)arg);
  pthread_t tid=pthread_self();
  printf("thread num %d and ID::%lu\n",num,(unsigned long)tid);
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
    printf("ALL THREADS FINISHED.\n");
    return 0;
}


/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
thread num 1 and ID::131028444247744
thread num 2 and ID::131028435855040
thread num 3 and ID::131028427462336
thread num 4 and ID::131028312127168
thread num 5 and ID::131028419069632
ALL THREADS FINISHED.

*/
