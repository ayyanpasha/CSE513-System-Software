/*
Question:  Write a program to execute `ls -Rl` by the following system calls 
    2. `execlp` 
*/
// Name: Ayyan Pasha
// Roll Number: MT2024029

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
