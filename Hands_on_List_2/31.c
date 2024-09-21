/*
============================================================================
Name : 31.c
Author : Ayyan Pasha
Description : Write a program to create a semaphore and initialize value to the semaphore.
                i.  Create a binary semaphore
                ii. Create a counting semaphore
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>

union semun
{
    int val;                   // Value for SETVAL
    struct semid_ds *buf;      // Buffer for IPC_STAT, IPC_SET.
    unsigned short int *array; // Array for GETALL, SETALL.
};

// Creating binary semaphore and initializing value to the semaphore.
int main()
{
    union semun arg;
    key_t k = ftok(".", 'a');
    int semid = semget(k, 1, IPC_CREAT | 0666);

    int choice;
    printf("Choose an option:\n1.) Binary Semaphore\n2.) Counting Semaphore\n=> ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Creating binary semaphore\n");
        arg.val = 1; // Binary semaphore.
        break;
    case 2:
        printf("Creating counting semaphore\n");
        arg.val = 5; // Counting semaphore.
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
    
    // Set value of semaphore.
    semctl(semid, 0, SETVAL, arg);
    return (0);
}

/*
ayyanpasha@ayyanpasha-QEMU-Virtual-Machine:~/Desktop/hands_on_list_2$ ./a.out 
Choose an option:
1.) Binary Semaphore
2.) Counting Semaphore
=> 1
Creating binary semaphore
ayyanpasha@ayyanpasha-QEMU-Virtual-Machine:~/Desktop/hands_on_list_2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x610200d4 0          ayyanpasha 666        1         

ayyanpasha@ayyanpasha-QEMU-Virtual-Machine:~/Desktop/hands_on_list_2$ ./a.out 
Choose an option:
1.) Binary Semaphore
2.) Counting Semaphore
=> 2
Creating counting semaphore
ayyanpasha@ayyanpasha-QEMU-Virtual-Machine:~/Desktop/hands_on_list_2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x610200d4 0          ayyanpasha 666        1  
*/