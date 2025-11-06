/*
========================================================================================================================================================================================
Name : 18.c
Author : Kartavyakumar Patel
Description : 18. Write a program to find out total number of directories on the pwd.
              execute ls -l | grep ^d | wc ? Use only dup2.

Date : 17th sept, 2025
========================================================================================================================================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
   int fd1[2];
   pipe(fd1);
   if(!fork())
   {
   close(1);
   
   dup2(fd1[1],1);
   close(fd1[0]);
   execlp("ls","ls","-l",NULL);//Replaces current process with a new program.
   }
   else
   {
     int fd2[2];
     pipe(fd2);
     if(!fork())
     {
     close(fd1[1]);
     close(fd2[0]);
     close(0);
     dup2(fd1[0],0);
     close(1);
     dup2(fd2[1],1);
     execlp("grep","grep","^d",NULL);//Replaces current process with a new program.
     }
     else
     {
      close(fd1[0]);
      close(fd1[1]);
      
      close(0);
      dup2(fd2[0],0);//redirects the pipe’s read end to standard input. 
                    // read data coming through the pipe instead of the keyboard.
      close(fd2[1]);
      execlp("wc","wc",NULL);//Replaces current process with a new program.
     }
   }
   return 0;
}

/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ cc 18.c
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
      0       0       0


*/
