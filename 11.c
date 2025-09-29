/*
========================================================================================================================================================================================
Name : 11.c
Author : Kartavyakumar Patel
Description : 11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal use sigaction system call.

Date : 29th sept, 2025
========================================================================================================================================================================================
*/
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
int main()
{

struct sigaction sig;
sig.sa_handler=SIG_IGN;//set and ignire terminate
sigemptyset(&sig.sa_mask);
sig.sa_flags=0;
sigaction(SIGINT,&sig,NULL);

printf("SIG_IGN UP and ignore to terminate\n");
 
 sleep(5);
 
sig.sa_handler=SIG_DFL; //reset 
sigaction(SIGINT,&sig,NULL);
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
^C^C^C^C^CSIG_IGN reset you can treminate process
you can treminate process
you can treminate process
you can treminate process
^C

*/
