/*
========================================================================================================================================================================================
Name : 23.c
Author : Kartavyakumar Patel
Description : 23. Write a program to print the maximum number of files can be opened within a process and size of a pipe (circular buffer).

Date : 18th sept, 2025
========================================================================================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include<sys/resource.h>
#include <sys/stat.h>

int main()
{
 int fd;
 long no_file;
 long size;
 fd=mkfifo("FIFO23",S_IRWXU);
 //It is a macro defined in <sys/stat.h>
 //that represents read, write, and execute permissions for the file owner (user).
 if(fd==-1)
 {perror("ERR");}
 else
 {
  no_file=sysconf(_SC_OPEN_MAX);
  
  if(no_file==-1)
  {
   perror("Err:");
   return 1;
  }
  else
  printf("MAX FILE that can be open:: %ld\n",no_file);
  
  size=pathconf("FIFO23",_PC_PIPE_BUF);
  if(size==-1)
  {
   perror("Err:");
   return 1;
  }
  else
  printf("MAX FILE SIZE:: %ld\n",size);
  
  
 }

}

/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
MAX FILE that can be open:: 1024
MAX FILE SIZE:: 4096

*/
