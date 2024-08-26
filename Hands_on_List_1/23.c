// Question : Write a program to create a Zombie state of the running program
// Name: Ayyan Pasha
// Roll Number: MT2024029

#include <sys/types.h> // Import for `fork` system call
#include <unistd.h>    // Import for `fork` system call
#include <stdio.h>     // Import for `printf` function
#include <stdlib.h>		// Import `wait` to cleanup zombie state

int main(){
	if(fork()){
		printf("Parent PID: %d\n",getpid());

		printf("Putting the parent to sleep for 10s!\n");
        sleep(10);
        printf("Parent is now awake!\n");

		wait(NULL);
	}else{
		printf("Child PID: %d\n",getpid());

		printf("Putting the child to sleep for 5s!\n");
        sleep(5);
        printf("Child is now awake!\n");

		printf("Child is exiting now\n");
		_exit(0);
	}
	return 0;
}

/*
./a.out 
Parent PID: 9539
Putting the parent to sleep for 10s!
Child PID: 9540
Putting the child to sleep for 5s!
Child is now awake!
Child is exiting now
Parent is now awake!

When checked for Zombie state when child exited and parent sleeping
ps -e -o pid,ppid,state,comm | grep 'Z'
9540  9539 Z+   <defunct>

*/