/*
============================================================================
Name : 30_d.c
Author : Ayyan Pasha
Description : Write a program to create a shared memory.
                d. Remove the shared memory
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
    int shmid = shmget(key, 1024, 0);

    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        printf("Delete unsuccessful\n");
    }
    else
    {
        printf("Delete successful\n");
    }

    return (0);
}

/*
ayyanpasha@ayyanpasha-QEMU-Virtual-Machine:~/Desktop/hands_on_list_2$ ./a.out 
Delete successful
ayyanpasha@ayyanpasha-QEMU-Virtual-Machine:~/Desktop/hands_on_list_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages 

*/