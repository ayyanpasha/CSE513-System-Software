/*
============================================================================
Name : 27d.c
Author : Ayyan Pasha
Description : Write a program to execute `ls -Rl` by the following system calls 
    d. `execv` 
Date: 26th Aug, 2024.
============================================================================
*/

#include <unistd.h> // Import for `execv` function
#include <stdio.h>  // Import for `printf` function

int main(){
	char *args[] = {"/bin/ls","-Rl",NULL};
	
	printf("===== Output using execv =====\n");
	execv(args[0],args);
	printf("\n");
	return 0;
}
