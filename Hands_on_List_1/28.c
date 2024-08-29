// Question : Write a program to get maximum and minimum real time priority
// Name: Ayyan Pasha
// Roll Number: MT2024029

#include <sched.h> // Import for `sched_get_priority_*` functions
#include <stdio.h> // Import for `printf`

int main(){
	int maxPriority,minPriority;
	if((maxPriority = sched_get_priority_max(SCHED_RR)) == -1){
		perror("Error while getting Max Priority\n");
		return 0;
	}
	printf("Max Priority: %d\n",maxPriority);

	if((minPriority = sched_get_priority_min(SCHED_RR)) == -1){
		perror("Error while getting Min Priority\n");
		return 0;
	}
	printf("Min Priority: %d\n",minPriority);
	return 0;
}

/*
./a.out
Max Priority: 47
Min Priority: 15
*/