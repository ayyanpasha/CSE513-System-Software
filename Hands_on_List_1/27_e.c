/*
============================================================================
Name : 27e.c
Author : Ayyan Pasha
Description : Write a program to execute `ls -Rl` by the following system calls 
    e. `execvp` 
Date: 26th Aug, 2024.
============================================================================
*/

#include <unistd.h> // Import for `execvp` function
#include <stdio.h>  // Import for `printf` function

int main(){
	char *args[] = {"/bin/ls","-Rl",NULL};
	
	printf("===== Output using execvp =====\n");
	execvp(args[0],args);
	printf("\n");
	return 0;
}
