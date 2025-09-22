/*
========================================================================================================================================================================================
Name : 15.c
Author : Kartavyakumar Patel
Description : 15. Write a simple program to send some data from parent to the child process.

Date : 16th sept, 2025
========================================================================================================================================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<string.h>

int main()
{
int file_des[2];
char msg[]="I am PIPE and COmmunication with";
char re_msg[50];

if(pipe(file_des)==-1)
{
printf("ERROR: PIPE");
return 1;
}

if(!fork())
{
 close(file_des[1]);
 printf("Child only for read\n");
 read(file_des[0],re_msg,sizeof(re_msg));
 printf("READ MSG::\n%s\n",re_msg);
 close(file_des[0]); 
}
else
{
 close(file_des[0]); 
 write(file_des[1],msg,strlen(msg)+1);
 close(file_des[1]);
}

return 0;
}


/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
Child only for read
READ MSG::
I am PIPE and COmmunication with

*/
