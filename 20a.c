/*
========================================================================================================================================================================================
Name : 20a.c
Author : Kartavyakumar Patel
Description : 20. Write two programs so that both can communicate by FIFO -Use one way communication.

Date : 18th sept, 2025
========================================================================================================================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
  int file_des;
  mkfifo("fifo_20a",0666);
  char para1[100];
  while(1)
  {
  file_des=open("fifo_20a",O_RDONLY);
  read(file_des,para1,sizeof(para1));
  printf("READ DATA::\n%s\n",para1);
  close(file_des);
  }
  return 0;
}



/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
READ DATA::
hello i am fifo and half duplex

READ DATA::
means one way communication boss



*/
