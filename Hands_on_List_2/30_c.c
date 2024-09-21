/*
============================================================================
Name : 30_c.c
Author : Ayyan Pasha
Description : Write a program to create a shared memory.
                c. Detach the shared memory
Date: 20th Sep, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, IPC_CREAT | 0666);

    char *data = shmat(shmid, (void *)0, 0);
    printf("Detaching\n");
    shmdt(data);

    return (0);
}

/*
ayyanpasha@ayyanpasha-QEMU-Virtual-Machine:~/Desktop/hands_on_list_2$ ./a.out 
Detaching
*/