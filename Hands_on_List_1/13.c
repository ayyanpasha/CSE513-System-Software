// Question : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not (check in $man 2 select).
// Name: Ayyan Pasha
// Roll Number: MT2024029

#include <sys/time.h>  // Import for `timeval` system call
#include <sys/types.h> // Import for `FD_SET` system call
#include <unistd.h>    // Import for `select` system call
#include <stdio.h>     // Imports for `perror & `printf` function

int main(int argc, char *argv[]){
	fd_set readFDSet, writeFDSet;
	FD_SET(STDIN_FILENO,&readFDSet);
	FD_SET(STDOUT_FILENO,&writeFDSet);

	struct timeval time;
	time.tv_sec = 10;
	time.tv_usec = 0;

	int returnVal;
	returnVal = select(STDIN_FILENO+1,&readFDSet,&writeFDSet,NULL,&time);

	if(returnVal == -1){
		perror("ERROR\n");
	}else if(returnVal == 0){
		printf("No data was given for 10 seconds\n");
	}else{
		printf("The data is now available\n");
	}
	return 0;
}

/*
./a.out
s
The data is now available
*/

/*
./a.out
No data was given for 10 seconds
*/