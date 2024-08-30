/*
============================================================================
Name : 27b.c
Author : Ayyan Pasha
Description : Write a program to execute `ls -Rl` by the following system calls 
    b. `execlp` 
Date: 26th Aug, 2024.
============================================================================
*/

#include <unistd.h> // Import for `execlp` function
#include <stdio.h>  // Import for `printf` function

int main(){
	char *command_line = "/bin/ls";
	char *options = "-Rl";
	
	printf("===== Output using execlp =====\n");
	execlp(command_line,command_line,options,NULL);
	printf("\n");
	return 0;
}
