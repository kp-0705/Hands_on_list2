/*
========================================================================================================================================================================================
Name : 13rec.c
Author : Kartavyakumar Patel
Description : 13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call). 
              Find out whether the first program is able to catch the signal or not.
            
Date : 29th sept, 2025
========================================================================================================================================================================================
*/
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void handle(int seg)
{
printf("Caught SIGNAL %d.....\n",seg);
}

int main()
{
printf("Process ID:: %d\n",getpid());
signal(SIGSTOP,handle);
printf("Waiting....\n");

while(1)
{
pause();// Waiting for signals
}
return 0;
}
/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ gcc 13rec.c -o rec
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ gcc 13send.c -o send
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./rec
sigaction:: : Invalid argument
Process ID:: 15828
Waiting....

[2]+  Stopped                 ./rec

*/
