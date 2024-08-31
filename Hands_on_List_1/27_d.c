/*
============================================================================
Name : 27_d.c
Author : Ayyan Pasha
Description : Write a program to execute `ls -Rl` by the following system calls 
    d. `execv` 
Date: 26th Aug, 2024.
============================================================================
*/

#include <unistd.h> // Import for `execv` function
#include <stdio.h>  // Import for `printf` function

int main(){
	char *args[] = {"/bin/ls","-Rl",NULL};
	
	printf("===== Output using execv =====\n");
	execv(args[0],args);
	printf("\n");
	return 0;
}
/*
./a.out 
===== Output using execl =====
total 488
-rw-r--r--  1 ayyanpasha  staff    819 Aug 29 12:29 01_a.c
-rw-r--r--  1 ayyanpasha  staff    772 Aug 29 12:30 01_b.c
-rw-r--r--  1 ayyanpasha  staff   1295 Aug 29 12:29 01_c.c
-rw-r--r--  1 ayyanpasha  staff    249 Aug 22 09:05 01_shell.sh
-rw-r--r--  1 ayyanpasha  staff    446 Aug 29 12:30 02.c
-rw-r--r--  1 ayyanpasha  staff    997 Aug 29 12:30 03.c
-rw-r--r--  1 ayyanpasha  staff   1184 Aug 29 12:31 04.c
-rw-r--r--  1 ayyanpasha  staff    997 Aug 29 12:32 05.c
-rw-r--r--  1 ayyanpasha  staff    754 Aug 29 12:33 06.c
-rw-r--r--  1 ayyanpasha  staff   2043 Aug 29 12:33 07.c
-rw-r--r--  1 ayyanpasha  staff   1765 Aug 29 12:33 08.c
-rw-r--r--  1 ayyanpasha  staff   1915 Aug 29 12:34 09.c
-rw-r--r--  1 ayyanpasha  staff   1369 Aug 29 12:35 10.c
-rw-r--r--  1 ayyanpasha  staff   1344 Aug 29 12:38 11_a.c
-rw-r--r--  1 ayyanpasha  staff   1408 Aug 29 12:36 11_b.c
-rw-r--r--  1 ayyanpasha  staff   1382 Aug 29 12:36 11_c.c
-rw-r--r--  1 ayyanpasha  staff   2782 Aug 29 12:37 12.c
-rw-r--r--  1 ayyanpasha  staff   1217 Aug 29 12:39 13.c
-rw-r--r--  1 ayyanpasha  staff   1635 Aug 31 09:29 14.c
-rw-r--r--  1 ayyanpasha  staff    480 Aug 29 12:39 15.c
-rw-r--r--  1 ayyanpasha  staff   1406 Aug 29 12:40 16_a.c
-rw-r--r--  1 ayyanpasha  staff   1821 Aug 29 12:41 16_b.c
-rw-r--r--  1 ayyanpasha  staff   2037 Aug 29 12:49 17_a.c
-rw-r--r--  1 ayyanpasha  staff   2444 Aug 29 12:43 17_b.c
-rw-r--r--  1 ayyanpasha  staff   3097 Aug 30 20:29 18.c
-rw-r--r--  1 ayyanpasha  staff   1229 Aug 29 12:44 19.c
-rw-r--r--  1 ayyanpasha  staff    826 Aug 29 12:44 20.c
-rw-r--r--  1 ayyanpasha  staff    652 Aug 29 12:44 21.c
-rw-r--r--  1 ayyanpasha  staff    976 Aug 29 12:45 22.c
-rw-r--r--  1 ayyanpasha  staff   1256 Aug 29 12:45 23.c
-rw-r--r--  1 ayyanpasha  staff   1125 Aug 29 12:45 24.c
-rw-r--r--  1 ayyanpasha  staff   1638 Aug 31 09:34 25.c
-rw-r--r--  1 ayyanpasha  staff    600 Aug 29 12:46 26.c
-rw-r--r--  1 ayyanpasha  staff    610 Aug 29 12:46 27_a.c
-rw-r--r--  1 ayyanpasha  staff    614 Aug 29 12:47 27_b.c
-rw-r--r--  1 ayyanpasha  staff    619 Aug 29 12:47 27_c.c
-rw-r--r--  1 ayyanpasha  staff    567 Aug 29 12:48 27_d.c
-rw-r--r--  1 ayyanpasha  staff    571 Aug 29 12:48 27_e.c
-rw-r--r--  1 ayyanpasha  staff    840 Aug 29 12:48 28.c
-rw-r--r--  1 ayyanpasha  staff   1465 Aug 30 20:15 29.c
-rw-r--r--  1 ayyanpasha  staff   4434 Aug 29 19:03 30.c
-rwxrwxrwx  1 ayyanpasha  staff    296 Aug 29 19:02 30.sh
-rwxr-xr-x  1 ayyanpasha  staff  33536 Aug 26 19:02 Q14
-rwxr-xr-x  1 ayyanpasha  staff  33464 Aug 31 09:35 a.out
drwxr-xr-x  4 ayyanpasha  staff    128 Aug 30 20:30 support_folder

./support_folder:
total 16
-rwx------  1 ayyanpasha  staff  24 Aug 30 18:01 18-file.txt
-rwx------  1 ayyanpasha  staff   1 Aug 29 12:01 ticket_file.txt
*/