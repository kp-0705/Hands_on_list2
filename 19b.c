/*
========================================================================================================================================================================================
Name : 19b.c
Author : Kartavyakumar Patel
Description : 19. Create a FIFO file by
              b. mkfifo command
        
Date : 17th sept, 2025
========================================================================================================================================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	execlp("mkfifo","mkfifo","fifo1",NULL);

	return 0;
}
/*
Output:: 

*/
