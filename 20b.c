/*
========================================================================================================================================================================================
Name : 20b.c
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
#include<string.h>

int main()
{
 int file_des;
  mkfifo("fifo_20a",0666);
  char para2[100];
  while(1)
  {
  file_des=open("fifo_20a",O_WRONLY);
  fgets(para2,100,stdin);
  write(file_des,para2,strlen(para2)+1);
  close(file_des);
  }
  return 0;
}


/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
hello i am fifo and half duplex
means one way communication boss


*/
