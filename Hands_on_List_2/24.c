/*
============================================================================
Name : 24.c
Author : Ayyan Pasha
Description : Write a program to create a message queue and print the key and message queue id.
Date: 20th Sep, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

// Create a message queue.
int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0666);
    printf("Key: %d, ID: %d\n", key, msqid);
    return(0);
}

/*
ayyanpasha@ayyanpasha-QEMU-Virtual-Machine:~/Desktop/hands_on_list_2$ ./a.out 
Key: 1627521236, ID: 0
*/