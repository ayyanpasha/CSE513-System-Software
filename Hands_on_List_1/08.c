/*
============================================================================
Name : 8.c
Author : Ayyan Pasha
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of file is reached.
Date: 24th Aug, 2024.
============================================================================
*/

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

	char *buffer;

	int readByte;
	int writeByte;
	
	while((readByte = read(sourceFD,buffer, 1)) > 0 ){
		if(buffer[0] == '\n') getchar();
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

/*
./a.out 01_a.c
// Question: Create a soft link file using the `symlink` system call

// Name: Ayyan Pasha

// Roll Number: MT2024029



#include<unistd.h> // import symlink

#include<stdio.h>  // import printf and perror



int main(int argc, char *argv[]){



	if(argc != 3){

		printf("Enter source and target file Name in arguement\n");

		return 0;

	}

	const char *source = argv[1];

	const char *target = argv[2];



	int status = symlink(source,target);

	if(status == -1){

		perror("symlink");

		printf("Error while creating link\n");

	}else{

		printf("Link created successfully\n");

	}

	return 0;

}

*/
