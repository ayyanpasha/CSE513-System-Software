/*
============================================================================
Name : 21.c
Author : Ayyan Pasha
Description : Write a program, call fork and print the parent and child process id.
Date: 26th Aug, 2024.
============================================================================
*/

#include <sys/types.h> // Import for `fork` & `getpid` system call
#include <unistd.h>    // Import for `fork` & `getpid` system call
#include <stdio.h>     // Import for printf function

int main(){
	if(!fork()){
		printf("Child PID: %d\n",getpid());
		printf("Parent PID: %d\n",getppid());
	}
	return 0;
}

/*
./a.out
Child PID: 8330
Parent PID: 1
*/