/*
============================================================================
Name : 15.c
Author : Ayyan Pasha
Description : Write a program to display the environmental variable of the user (use environ).
Date: 27th Aug, 2024.
============================================================================
*/

#include <stdio.h>	// Import `NULL` and `environ`

extern char ** environ;

int main(){
	char **it = environ;
	while(*it){
		printf("%s\n",*it);
		it++;
	}
	return 0;
}
