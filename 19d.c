/*
========================================================================================================================================================================================
Name : 19d.c
Author : Kartavyakumar Patel
Description : 19. Create a FIFO file by
              d. mknod system call

Date : 17th sept, 2025
========================================================================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
 if(mknod("fifo_19d",S_IFIFO | 0666,0)==-1)
  {
   perror("MKNOD::");
   return 1;
  }
  printf("Successful\n");
  return 0;
}

/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
Successful


*/
