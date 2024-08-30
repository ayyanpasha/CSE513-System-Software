/*
============================================================================
Name : 26.c
Author : Ayyan Pasha
Description : Write a program to execute an executable program. 
    1. Use some executable program 
    2. Pass some input to an executable program. (for example execute an executable of `$./a.out name`)
Date: 26th Aug, 2024.
============================================================================
*/


#include <unistd.h>	// Import execl

int main(){
	char *exec_path = "Q14";
	char *argv = "10.c";
	execl(exec_path,exec_path,argv,NULL);

	return 0;
}

/*
./a.out
Regular File
*/
