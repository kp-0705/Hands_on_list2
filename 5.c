/*
========================================================================================================================================================================================
Name : 5.c
Author : Kartavyakumar Patel
Description : 5. Write a program to print the system limitation of
              a. maximum length of the arguments to the exec family of functions.
              b. maximum number of simultaneous process per user id.
              c. number of clock ticks (jiffy) per second.
              d. maximum number of open files
              e. size of a page
              f. total number of pages in the physical memory
              g. number of currently available pages in the physical memory.
              
Date : 28th sept, 2025
========================================================================================================================================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main()
{
 printf("max_argument:: %ld\n",sysconf(_SC_ARG_MAX));
 printf("max_simultaneous_pid:: %ld\n",sysconf(_SC_CHILD_MAX));
 printf("CLK_TCK (clock ticks per second): %ld\n", sysconf(_SC_CLK_TCK));
 printf("OPEN_MAX (max open files): %ld\n", sysconf(_SC_OPEN_MAX));
 printf("PAGE_SIZE (bytes per page): %ld\n", sysconf(_SC_PAGESIZE));
 printf("Total pages in physical memory: %ld\n", sysconf(_SC_PHYS_PAGES));
 printf("Available pages in physical memory: %ld\n", sysconf(_SC_AVPHYS_PAGES));


return 0;
}

/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
max_argument:: 2097152
max_simultaneous_pid:: 30293
CLK_TCK (clock ticks per second): 100
OPEN_MAX (max open files): 1024
PAGE_SIZE (bytes per page): 4096
Total pages in physical memory: 1973604
Available pages in physical memory: 902248


*/
