// Question : Write a program, call fork and print the parent and child process id.
// Name: Ayyan Pasha
// Roll Number: MT2024029

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