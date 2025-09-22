/*
========================================================================================================================================================================================
Name : 16.c
Author : Kartavyakumar Patel
Description : 16. Write a program to send and receive data from parent to child vice versa. Use two way communication.

Date : 16th sept, 2025
========================================================================================================================================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<string.h>

int main()
{
int p_c[2];
int c_p[2];
char msg[]="what is your ID\n";
char re_msg[50];

if(pipe(c_p)==-1 || pipe(p_c)==-1 )
{
printf("ERROR: PIPE");
return 1;
}

if(!fork())
{
close(p_c[1]);
close(c_p[0]);
read(p_c[0],re_msg,sizeof(re_msg));
printf("child rec:%s\n",re_msg);
sprintf(re_msg,"My Id is %d",getpid());
write(c_p[1],re_msg,strlen(re_msg)+1);
close(p_c[0]);
close(c_p[1]);

}
else
{
close(p_c[0]);
close(c_p[1]);
write(p_c[1],msg,strlen(msg)+1);
read(c_p[0],re_msg,sizeof(re_msg));
printf("parent rec:%s\n",re_msg);
close(p_c[1]);
close(c_p[0]);
}

return 0;
}


/*
 Output:
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
child rec:what is your ID

parent rec:My Id is 356202


*/
