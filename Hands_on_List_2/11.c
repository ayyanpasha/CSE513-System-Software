/*
============================================================================
Name : 11.c
Author : Ayyan Pasha
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - use sigaction system call.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <bits/sigaction.h>

int main(){
    struct sigaction act;
    
    memset(&act,0,sizeof(act));
    act.sa_handler = SIG_IGN;
    printf("Ignoring SIGINT\n");
    sigaction(SIGINT,&act,NULL);
    sleep(7);
    
    memset(&act,0,sizeof(act));
    act.sa_handler = SIG_DFL;
    printf("\nDefault of SIGINT\n");
    sigaction(SIGINT,&act,NULL);
    sleep(7);
    
    return(0);
}

/*
ayyanpasha@ayyanpasha-QEMU-Virtual-Machine:~/Desktop/hands_on_list_2$ ./a.out 
Ignoring SIGINT

Default of SIGINT
ayyanpasha@ayyanpasha-QEMU-Virtual-Machine:~/Desktop/hands_on_list_2$ ./a.out 
Ignoring SIGINT
^C^C^C
Default of SIGINT
^C
*/