// Question: Write a program to copy file1 into file2 ($cp file1 file2).
// Name: Ayyan Pasha
// Roll Number: MT2024029

#include <sys/types.h>	// Import system call data types
#include <sys/stat.h>	// Import micro for system call
#include <fcntl.h>	// Import file control
#include <unistd.h>	// Import read and write
#include <stdio.h>	// Import perror

int main(int argc, char *argv[]){
	if(argc < 3){
		perror("Source and Destination File to be entered\n");
		return 0;
	}
	char *buffer[100];
	int readByte;
	int writeByte;

	int sourceFD = open(argv[1],O_RDONLY);
	int destinationFD = -1;
	if(sourceFD != -1) destinationFD = open(argv[2], O_CREAT | O_RDWR, S_IRWXU);

	if(destinationFD == -1){
		perror("Error in source / destination File \n");
		return 0;
	}

	while((readByte = read(sourceFD,buffer,1024)) > 0){
		writeByte = write(destinationFD, buffer, readByte);
		if(writeByte == -1){
			perror("Error in writing into file\n");
			return 0;
		}
	}
	if(readByte == -1){
		perror("Error in reading from source file\n");
	}else{
		printf("Successfully copied the file contents\n");
	}

	close(sourceFD);
	close(destinationFD);
	return 0;
}
