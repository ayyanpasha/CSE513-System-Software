/*
============================================================================
Name : 19.c
Author : Ayyan Pasha
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 26th Aug, 2024.
============================================================================
*/

#include <sys/time.h>  // Import for `gettimeofday` system call
#include <sys/types.h> // Import for Micros
#include <unistd.h>    // Import for `getpid` system call
#include <stdio.h>     // Import for printf
#include <mach/mach_time.h>	//Import time from Mac

// Function to convert elapsed time to nanoseconds
uint64_t convert_to_nanoseconds(uint64_t elapsed) {
    static mach_timebase_info_data_t timebase_info = {0};
    if (timebase_info.denom == 0) {
        mach_timebase_info(&timebase_info);
    }
    return (elapsed * timebase_info.numer) / timebase_info.denom;
}

int main(){
	int start,end,pid;
	struct timeval time;

	start = mach_absolute_time();
	pid = getpid();
	end = mach_absolute_time();

	uint64_t elapsed_time = convert_to_nanoseconds(end - start);
	
	printf("PID: %d\n", pid);
	printf("Time Taken: %llu ns\n",elapsed_time);
	return 0;
}

/*
./a.out
PID: 7289
Time Taken: 41 ns
*/
