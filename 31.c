/*
========================================================================================================================================================================================
Name : 31.c
Author : Kartavyakumar Patel
Description : 31. Write a program to create a semaphore and initialize value to the semaphore.
              a. create a binary semaphore
              b. create a counting semaphore

Date : 20th sept, 2025
========================================================================================================================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>

int main()
{
sem_t b_s;
sem_t c_s;

if(sem_init(&b_s,0,1)!=0)
 {
    perror("sem_init");
        exit(1);
 }
 if(sem_init(&c_s,0,6)!=0)
 {
    perror("sem_init");
        exit(1);
 }

   printf("Binary semaphore and counting semaphore init\n");
  int val;
  if (sem_getvalue(&b_s, &val) == 0) {
    printf("Binary semaphore value = %d\n", val);}
  if (sem_getvalue(&c_s, &val) == 0) {
    printf("Counting semaphore value = %d\n", val);}
  
  if (sem_destroy(&b_s) != 0) {
        perror("destroy binary_semaphore)");
        exit(1);
    }
    
    printf("\n Binary semaphore deleted!\n");

    if (sem_destroy(&c_s) != 0) {
        perror("destroy counting_semaphore)");
        exit(1);
    }
    
    printf("\n Counting semaphore deleted!\n");
  

return 0;
}

/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
Binary semaphore and counting semaphore init
Binary semaphore value = 1
Counting semaphore value = 6

 Binary semaphore deleted!

 Counting semaphore deleted!
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     


*/
