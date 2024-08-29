/*
Question:  Write a program to execute `ls -Rl` by the following system calls 
    4. `execv` 
*/
// Name: Ayyan Pasha
// Roll Number: MT2024029

#include <unistd.h> // Import for `execv` function
#include <stdio.h>  // Import for `printf` function

int main(){
	char *args[] = {"/bin/ls","-Rl",NULL};
	
	printf("===== Output using execv =====\n");
	execv(args[0],args);
	printf("\n");
	return 0;
}
