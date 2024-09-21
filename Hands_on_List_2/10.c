/*
============================================================================
Name : 10.c
Author : Ayyan Pasha
Description : Write a separate program using sigaction system call to catch the following signals.
                i.   SIGSEGV
                ii.  SIGINT
                iii. SIGFPE
Date: 20th Sep, 2024.
============================================================================
*/

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <bits/sigaction.h>

void catch (int sig){
    printf("Signal Caught - %d\n", sig);
    exit(0);
}

int main(){
    int choice = 0;
    printf("Enter 1 for sigsegv 2 for sigint ... so on\n");
    scanf("%d", &choice);

    struct sigaction ac;
    memset(&ac, 0, sizeof(ac));
    ac.sa_handler = catch;

    if (choice == 1){
        sigaction(SIGSEGV, &ac, NULL);
        char *c = NULL;
        printf("%c", *c);
    }
    else if (choice == 2){
        sigaction(SIGINT, &ac, NULL);
        for (;;);
    }
    else if (choice == 3){
        sigaction(SIGFPE, &ac, NULL);
        int x, y;
        printf("Enter 0 to generate FPE: ");
        scanf("%d", &y);
        x = 1 / y;
        printf("%d\n", x);
    }
    return (0);
}

/*
ayyanpasha@ayyanpasha-QEMU-Virtual-Machine:~/Desktop/hands_on_list_2$ ./a.out 
Enter 1 for sigsegv 2 for sigint ... so on
1 
Signal Caught - 11
ayyanpasha@ayyanpasha-QEMU-Virtual-Machine:~/Desktop/hands_on_list_2$ ./a.out 
Enter 1 for sigsegv 2 for sigint ... so on
2
^CSignal Caught - 2
ayyanpasha@ayyanpasha-QEMU-Virtual-Machine:~/Desktop/hands_on_list_2$ ./a.out 
Enter 1 for sigsegv 2 for sigint ... so on
3
Enter 0 to generate FPE: 0
0
ayyanpasha@ayyanpasha-QEMU-Virtual-Machine:~/Desktop/hands_on_list_2$ ./a.out 
Enter 1 for sigsegv 2 for sigint ... so on
3
Enter 0 to generate FPE: 1
1
ayyanpasha@ayyanpasha-QEMU-Virtual-Machine:~/Desktop/hands_on_list_2$ ./a.out 
Enter 1 for sigsegv 2 for sigint ... so on
3
Enter 0 to generate FPE: 2
0
ayyanpasha@ayyanpasha-QEMU-Virtual-Machine:~/Desktop/hands_on_list_2$ ./a.out 
Enter 1 for sigsegv 2 for sigint ... so on
3
Enter 0 to generate FPE: 3
0
*/