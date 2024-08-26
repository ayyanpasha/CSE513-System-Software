// Question : Write a program to create an orphan process
// Name: Ayyan Pasha
// Roll Number: MT2024029

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
