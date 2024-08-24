// Question : Write a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of file is reached.
// Name: Ayyan Pasha
// Roll Number: MT2024029
#include <sys/types.h> // Import for open system call.
#include <sys/stat.h>  // Import micros
#include <fcntl.h>     // Import File Control
#include <unistd.h>    // Import for read and write system call
#include <stdio.h>     // Import for perrro and printf functions

int main(int argc, char *argv[]){
	if(argc <= 1){
		perror("Please enter File Name\n");
		return 0;
	}

	int sourceFD = open(argv[1],O_RDONLY);

	char *buffer[1024];

	int readByte;
	int writeByte;
	
	while((readByte = read(sourceFD,buffer, 1024)) > 0 ){
		writeByte = write(STDOUT_FILENO,buffer,readByte);
		if(writeByte == -1){
			perror("Error while printing\n");
			return 0;
		}
	}
	if(readByte == -1){
		perror("Error in reading from File\n");
	}
	return 0;
}
