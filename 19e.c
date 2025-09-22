/*
========================================================================================================================================================================================
Name : 19e.c
Author : Kartavyakumar Patel
Description : 19. Create a FIFO file by
              e. mkfifo library function

Date : 17th sept, 2025
========================================================================================================================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
 if(mkfifo("fifo_19e",0666)==-1)
  {
   perror("MKNOD::");
   return 1;
  }
  printf("Successful MKFIFO\n");
  return 0;
}

/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
Successful MKFIFO


*/
