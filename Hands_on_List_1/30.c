// Question : Write a program to run a script at a specific time using a Daemon process
// Name: Ayyan Pasha
// Roll Number: MT2024029

#include <time.h>      // Import for time related stuff
#include <stdio.h>     // Import for printf
#include <sys/types.h> // Import for fork, setsid
#include <unistd.h>    // Import for fork, setsid

void runScript(){
    char *command_line = "/bin/ls";
	char *options = "-Rl";
	
	execl(command_line,command_line,options,NULL);
}

// Argument to be passed as hour minute second
// hour is mandatory
int main(int argc, char *argv[])
{

    time_t currentEpoch, deadlineEpoch; // Current system time & deadline time in epoch
    struct tm *deadline;                // Deadline in user readable format

    pid_t child;

    if (argc < 2){
        printf("Pass at least one argument\n");
        return 0;
    }
    time(&currentEpoch); // Get current time
    deadline = localtime(&currentEpoch);

    deadline->tm_hour = atoi(argv[1]);
    deadline->tm_min = argv[2] == NULL ? 0 : atoi(argv[2]);
    deadline->tm_sec = argv[3] == NULL ? 0 : atoi(argv[3]);

    deadlineEpoch = mktime(deadline); // Convert dealine to epoch

    if ((child = fork()) == 0)
    {
        setsid();
        do
        {
            time(&currentEpoch);
        } while (difftime(deadlineEpoch, currentEpoch) > 0);
        printf("Executing ls command in Daemon Process!\n");
        runScript();
    }
    return 0;
}
/*
./a.out 11 6 50
Executing ls command in Daemon Process!
total 456
-rw-r--r--  1 ayyanpasha  staff    650 Aug 22 09:22 01_a.c
-rw-r--r--  1 ayyanpasha  staff    603 Aug 23 18:20 01_b.c
-rw-r--r--  1 ayyanpasha  staff   1126 Aug 22 12:25 01_c.c
-rw-r--r--  1 ayyanpasha  staff    249 Aug 22 09:05 01_shell.sh
-rw-r--r--  1 ayyanpasha  staff    278 Aug 22 12:25 02.c
-rw-r--r--  1 ayyanpasha  staff    829 Aug 23 18:20 03.c
-rw-r--r--  1 ayyanpasha  staff   1017 Aug 25 10:50 04.c
-rw-r--r--  1 ayyanpasha  staff    830 Aug 23 18:13 05.c
-rw-r--r--  1 ayyanpasha  staff    586 Aug 24 18:40 06.c
-rw-r--r--  1 ayyanpasha  staff   1879 Aug 24 18:42 07.c
-rw-r--r--  1 ayyanpasha  staff   1597 Aug 29 10:14 08.c
-rw-r--r--  1 ayyanpasha  staff   1751 Aug 24 18:43 09.c
-rw-r--r--  1 ayyanpasha  staff   1204 Aug 24 18:40 10.c
-rw-r--r--  1 ayyanpasha  staff   1174 Aug 26 18:45 11_a.c
-rw-r--r--  1 ayyanpasha  staff   1237 Aug 25 12:11 11_b.c
-rw-r--r--  1 ayyanpasha  staff   1210 Aug 25 12:14 11_c.c
-rw-r--r--  1 ayyanpasha  staff   2612 Aug 25 16:06 12.c
-rw-r--r--  1 ayyanpasha  staff   1049 Aug 25 19:59 13.c
-rw-r--r--  1 ayyanpasha  staff   1437 Aug 26 14:52 14.c
-rw-r--r--  1 ayyanpasha  staff    312 Aug 27 00:15 15.c
-rw-r--r--  1 ayyanpasha  staff   1239 Aug 29 09:05 16_a.c
-rw-r--r--  1 ayyanpasha  staff   1655 Aug 26 15:32 16_b.c
-rw-r--r--  1 ayyanpasha  staff   2227 Aug 29 10:49 17.c
-rw-r--r--  1 ayyanpasha  staff      0 Aug 27 11:46 18_PENDING.c
-rw-r--r--  1 ayyanpasha  staff   1061 Aug 26 15:39 19.c
-rw-r--r--  1 ayyanpasha  staff    658 Aug 26 16:33 20.c
-rw-r--r--  1 ayyanpasha  staff    484 Aug 26 16:47 21.c
-rw-r--r--  1 ayyanpasha  staff    808 Aug 26 16:52 22.c
-rw-r--r--  1 ayyanpasha  staff   1088 Aug 26 18:22 23.c
-rw-r--r--  1 ayyanpasha  staff    957 Aug 26 18:55 24.c
-rw-r--r--  1 ayyanpasha  staff   1524 Aug 26 18:50 25.c
-rw-r--r--  1 ayyanpasha  staff    437 Aug 26 19:04 26.c
-rw-r--r--  1 ayyanpasha  staff    444 Aug 27 00:00 27_a.c
-rw-r--r--  1 ayyanpasha  staff    448 Aug 26 23:53 27_b.c
-rw-r--r--  1 ayyanpasha  staff    453 Aug 26 23:53 27_c.c
-rw-r--r--  1 ayyanpasha  staff    401 Aug 26 23:53 27_d.c
-rw-r--r--  1 ayyanpasha  staff    405 Aug 26 23:53 27_e.c
-rw-r--r--  1 ayyanpasha  staff    671 Aug 27 11:51 28.c
-rw-r--r--  1 ayyanpasha  staff   1337 Aug 27 12:15 29_PENDING.c
-rw-r--r--  1 ayyanpasha  staff   1591 Aug 29 11:05 30_PENDING.c
-rwxr-xr-x  1 ayyanpasha  staff  33536 Aug 26 19:02 Q14
-rwxr-xr-x  1 ayyanpasha  staff  33816 Aug 29 11:06 a.out
drwxr-xr-x  3 ayyanpasha  staff     96 Aug 29 10:42 support_folder

./support_folder:
total 8
-rwx------  1 ayyanpasha  staff  2 Aug 29 10:42 ticket_file.txt
*/