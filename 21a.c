/*
========================================================================================================================================================================================
Name : 21a.c
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
                fd = open("FIFO_21",O_RDONLY);
		read(fd,str1,100);
		
		printf("B READ DATA:\n%s\n",str1);
		close(fd);

                fd = open("FIFO_21",O_WRONLY);
                printf("B TO A:: \n");
		fgets(str2,100,stdin);
		write(fd,str2,strlen(str2)+1);
             	close(fd);
        }
        return 0;
}

/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ cc 21a.c
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
B READ DATA:
hello am i audible

B TO A:: 
yes , what about you
nice voice
B READ DATA:
we are in full duplex



*/
