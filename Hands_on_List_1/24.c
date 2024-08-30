/*
============================================================================
Name : 24.c
Author : Ayyan Pasha
Description : Write a program to create an orphan process
Date: 26th Aug, 2024.
============================================================================
*/

#include <sys/types.h> // Import for `fork` system call
#include <unistd.h>    // Import for `fork` system call
#include <stdio.h>     // Import for `printf` function

int main(){
	if(fork()){
		printf("Parent PID: %d\n", getpid());
        printf("Putting Parent to sleep for 5s\n");
        sleep(5);
		printf("Parent woke\n");
        printf("Exiting parent!\n");
		_exit(0);
	}else{
		printf("Child PID: %d\n", getpid());
        printf("Putting Child to sleep for 10s!\n");
        sleep(10);
        printf("Child is now awake!\n");
	}
	return 0;
}

/*
./a.out
Child A created !!!
Putting Child A to sleep for 5 secs
Parent waiting for Child C
Child B Created !!
Putting Child B to sleep for 10 secs
Child C Created !!
Putting Child C to sleep for 15 secs
Child A Woke up
Child B Woke up
Child C Woke up
Child C has exited with exit status: 0
*/