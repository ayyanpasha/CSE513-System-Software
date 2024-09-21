/*
============================================================================
Name : 15.c
Author : Ayyan Pasha
Description : Write a simple program to send some data from parent to the child process.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd[2];
	pipe(fd);

    // Child process.
	if(!fork()){
        printf("In child process\n");
		int c_value = 123;
		close(fd[0]);
        printf("Writing to pipe (in child process)\n");
		write(fd[1], &c_value, sizeof(int));
	}
    // Parent process.
	else{
        printf("In parent process\n");
		int p_value;
		close(fd[1]);
		read(fd[0], &p_value, sizeof(int));
		printf("Data from child in parent process: %d\n", p_value);
	}

	return(0);
}

/*
ayyanpasha@ayyanpasha-QEMU-Virtual-Machine:~/Desktop/hands_on_list_2$ ./a.out 
In parent process
In child process
Writing to pipe (in child process)
Data from child in parent process: 123
*/