/*
============================================================================
Name : 27c.c
Author : Ayyan Pasha
Description : Write a program to execute `ls -Rl` by the following system calls 
    c. `execle` 
Date: 26th Aug, 2024.
============================================================================
*/

#include <unistd.h> // Import for `execle` function
#include <stdio.h>  // Import for `printf` function

int main(){
	char *command_line = "/bin/ls";
	char *options = "-Rl";
	
	printf("===== Output using execle =====\n");
	execle(command_line,command_line,options,NULL,NULL);
	printf("\n");
	return 0;
}
