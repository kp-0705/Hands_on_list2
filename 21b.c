/*
========================================================================================================================================================================================
Name : 21b.c
Author : Kartavyakumar Patel
Description : 21. Write two programs so that both can communicate by FIFO -Use two way communications.

Date : 18th sept, 2025
========================================================================================================================================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
	int fd;
	mkfifo("FIFO_21",0666);

	char str1[100],str2[100];
	while(1)
	{
		fd = open("FIFO_21",O_WRONLY);
                printf("A TO B:: \n");
		fgets(str1,100,stdin);

		write(fd,str1,strlen(str1)+1);
		close(fd);

		fd = open("FIFO_21",O_RDONLY);

		read(fd,str2,sizeof(str2));

		printf("A READ DATA::\n%s\n",str2);
		close(fd);
	}
	return 0;
}


/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ cc 21b.c
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
A TO B:: 
hello am i audible
A READ DATA::
yes , what about you

A TO B:: 
we are in full duplex
A READ DATA::
nice voice

*/
