/*
========================================================================================================================================================================================
Name : 17.c
Author : Kartavyakumar Patel
Description : 17. Write a program to execute ls -l | wc.
              a. use dup
              b. use dup2
              c. use fcntl

Date : 16th sept, 2025
========================================================================================================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>


int main()
{
int file_d[2];
pid_t f_val;
int ch;

printf("Enter the num with respect to name ::\n");
printf("1. dup\n");
printf("2. dup2\n");
printf("3. fcntl\n");
printf("Enter your choice: ");
scanf("%d", &ch);

if(pipe(file_d)==-1)
{
printf("ERROR: PIPE");
return 1;
}
f_val=fork();
 if(f_val<0)
  {perror("FORK ERROR::");
 exit(1);}

switch(ch)
{
 case 1:
    if(f_val==0)
    {
    close(file_d[0]);
    close(1);
    dup(file_d[1]);
    close(file_d[1]);
    execlp("ls","ls","-l",NULL);
    perror("EXECLP ERROR LS::");
    }
    else
    {
    close(file_d[1]);
    close(0);
    dup(file_d[0]);
    close(file_d[0]);
    execlp("wc","wc",NULL);
    perror("EXECLP ERROR WC::"); 
    }
   break;
 case 2:
   if(f_val==0)
    {
    close(file_d[0]);
    dup2(file_d[1],STDOUT_FILENO);
    close(file_d[1]);
    execlp("ls","ls","-l",NULL);
    perror("EXECLP ERROR LS::");
    }
    else
    {
    close(file_d[1]);
    dup2(file_d[0],STDIN_FILENO);
    close(file_d[0]);
    execlp("wc","wc",NULL);
    perror("EXECLP ERROR WC::"); 
    }
   break;
 case 3:
   if(f_val==0)
    {
    close(file_d[0]);
    close(STDOUT_FILENO);
    fcntl(file_d[1],F_DUPFD,STDOUT_FILENO);
    close(file_d[1]);
    execlp("ls","ls","-l",NULL);
    perror("EXECLP ERROR LS::");
    }
    else
    
    {
    close(file_d[1]);
    close(STDIN_FILENO);
    fcntl(file_d[0],F_DUPFD,STDIN_FILENO);
    close(file_d[0]);
    execlp("wc","wc",NULL);
    perror("EXECLP ERROR WC::"); 
    }
   break;
 default:
 printf("Wrong Choice\n");
}

return 0;
}
/*
 Output:

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
Enter the num with respect to name ::
1. dup
2. dup2
3. fcntl
Enter your choice: 1
     38     335    1742
     
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ cc 17.c
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
Enter the num with respect to name ::
1. dup
2. dup2
3. fcntl
Enter your choice: 2
     38     335    1742
     
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ cc 17.c
dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out
Enter the num with respect to name ::
1. dup
2. dup2
3. fcntl
Enter your choice: 3
     38     335    1742


*/
