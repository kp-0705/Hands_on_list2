/*
========================================================================================================================================================================================
Name : 19c.c
Author : Kartavyakumar Patel
Description : 19. Create a FIFO file by
              c. use strace command to find out, which command (mknod or mkfifo) is better.
             

Date : 17th sept, 2025
========================================================================================================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
int main()
{
	if(!fork())
	{
		printf("\nUsing mkfifo:\n");
		execlp("strace","strace","-c","mkfifo","fifo1",NULL);
	}
	else
	{
		wait(0);
		printf("\nUsing mknod:\n");
		execlp("strace","strace","-c","mknod","fifo2","p",NULL);
	}
	return 0;
}
/*
Output:: 

dell@dell-Inspiron-3593:~/Desktop/MT2025059/Hands-on_List2$ ./a.out

Using mkfifo:
mkfifo: cannot create fifo 'fifo1': File exists
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
 37.58    0.000454         454         1           execve
 22.52    0.000272          14        19           mmap
 18.21    0.000220           7        31        23 openat
  4.97    0.000060           7         8           fstat
  4.06    0.000049          12         4           write
  3.97    0.000048           6         7           read
  3.64    0.000044           4        10           close
  1.16    0.000014           7         2         2 access
  0.99    0.000012           6         2           pread64
  0.75    0.000009           9         1         1 mknodat
  0.50    0.000006           2         3           brk
  0.41    0.000005           5         1           arch_prctl
  0.41    0.000005           5         1           set_tid_address
  0.41    0.000005           5         1           set_robust_list
  0.41    0.000005           5         1           rseq
  0.00    0.000000           0         5           mprotect
  0.00    0.000000           0         1           munmap
  0.00    0.000000           0         2         2 statfs
  0.00    0.000000           0         1           prlimit64
  0.00    0.000000           0         1           getrandom
------ ----------- ----------- --------- --------- ----------------
100.00    0.001208          11       102        28 total

Using mknod:
mknod: fifo2: File exists
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
 22.83    0.000063           3        19        12 openat
 18.84    0.000052           2        18           mmap
 16.30    0.000045           9         5           mprotect
  7.25    0.000020           2         7           read
  6.88    0.000019           4         4           write
  6.16    0.000017           1         9           close
  4.71    0.000013           6         2         2 statfs
  3.99    0.000011          11         1           munmap
  2.90    0.000008           1         7           fstat
  2.54    0.000007           2         3           brk
  1.45    0.000004           4         1         1 mknodat
  1.09    0.000003           1         2         2 access
  1.09    0.000003           3         1           prlimit64
  1.09    0.000003           3         1           getrandom
  0.72    0.000002           2         1           arch_prctl
  0.72    0.000002           2         1           set_tid_address
  0.72    0.000002           2         1           set_robust_list
  0.72    0.000002           2         1           rseq
  0.00    0.000000           0         2           pread64
  0.00    0.000000           0         1           execve
------ ----------- ----------- --------- --------- ----------------
100.00    0.000276           3        87        17 total


*/
