/*
============================================================================
Name : 12.c
Author : Ayyan Pasha
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to the parent process from the child process.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    // Child Process
    if (!fork())
    {
        sleep(5);
        printf("Child is waiting, pid: %d\n", getpid());
        kill(getppid(), 9);
        printf("Parent process killed\n");
        sleep(10);
    }
    else
    {
        printf("Parent Process, pid: %d\n", getpid());
        sleep(15);
    }

    return 0;
}

/*
ayyanpasha@ayyanpasha-QEMU-Virtual-Machine:~/Desktop/hands_on_list_2$ ./a.out 
Parent Process, pid: 6465
Child is waiting, pid: 6466
Parent process killed
Killed
*/