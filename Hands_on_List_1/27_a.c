/*
Question:  Write a program to execute `ls -Rl` by the following system calls 
    1. `execl` 
*/
// Name: Ayyan Pasha
// Roll Number: MT2024029

#include <unistd.h> // Import for `execl` function
#include <stdio.h>  // Import for `printf` function

int main(){
	char *command_line = "/bin/ls";
	char *options = "-Rl";
	
	printf("===== Output using execl =====\n");
	execl(command_line,command_line,options,NULL);
	printf("\n");
	return 0;
}
