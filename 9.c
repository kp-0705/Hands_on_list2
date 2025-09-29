/*
========================================================================================================================================================================================
Name : 9.c
Author : Kartavyakumar Patel
Description : 9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use signal system call.

Date : 29th sept, 2025
========================================================================================================================================================================================
*/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
int main()
{
 signal(SIGINT,SIG_IGN); // os to ignore ctrl+C
 printf("SIG_IGN UP and ignore to terminate\n");
 
 sleep(5);
 
 signal(SIGINT,SIG_DFL);// reset SIG_IGN
 printf("SIG_IGN reset you can treminate process\n");
 while(1)
 {
 printf("you can treminate process\n");
 sleep(2);
 }
 return 0;
}
/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
SIG_IGN UP and ignore to terminate
^C^C^C^CSIG_IGN reset you can treminate process
you can treminate process
you can treminate process
you can treminate process
^C
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ 

*/
