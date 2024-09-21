/*
============================================================================
Name : 13.c
Author : Ayyan Pasha
Description : Two programs: first program is waiting to catch SIGSTOP signal, the second program
              will send the signal (using kill system call). Find out whether the first program is able to catch
              the signal or not. (Second).
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    int pid;
    printf("Enter pid of process to stop\n");
    scanf("%d", &pid);

    printf("Sending SIGSTOP signal to process: %d\n", pid);
    kill(pid, SIGSTOP);

    printf("SIGSTOP signal sent\n");
    printf("Exiting current process (sender)\n");
    return (0);
}

/*
ayyanpasha@ayyanpasha-QEMU-Virtual-Machine:~/Desktop/hands_on_list_2$ ./13_s 
Enter pid of process to stop
6573
Sending SIGSTOP signal to process: 6573
SIGSTOP signal sent
Exiting current process (sender)
*/