/*
Question: Write a program to perform mandatory locking. 
    - Implement write lock 
*/
// Name: Ayyan Pasha
// Roll Number: MT2024029

#include <stdio.h>	// Import `printf` and `perror`
#include <fcntl.h>	// Import file control
#include <sys/stat.h>	// Import  system call micros
#include <sys/types.h>	// Import System call Macros
#include <unistd.h>

int main(int argc, char *argv[]){
	if(argc < 2){
		perror("Enter File Name\n");
		return 0;
	}

	struct flock lock,lockStatus;
	
	// Defining Lock Mechanism
	lock.l_type = F_WRLCK;		// Write Lock
	lock.l_whence = SEEK_SET;	// Seek to the start of the file
	lock.l_start = 0;		// Lock from the start of the file
	lock.l_len = 0;			// Locks the entire file
	lock.l_pid = getpid();

	int fd = open(argv[1],O_RDWR);
	if(fd == -1){
		perror("Error while opening the file\n");
		return 0;
	}

	fcntl(fd,F_GETLK,&lockStatus);

	if(lockStatus.l_type == F_WRLCK){
		printf("File has Write Lock\n");
	}else if(lockStatus.l_type == F_RDLCK){
		printf("File has Read Lock\n");
	}else{
		fcntl(fd,F_SETLK,lock);
		printf("File Lock has been applied\n");
		pause();
	}
	return 0;
}

/*
./a.out text.txt
File Lock has been applied
*/

//Other terminal

/*
./a.out text.txt
File has Write Lock
*/