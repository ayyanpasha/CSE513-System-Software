#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pthread_t thread;
    pthread_attr_t attr;
    int policy;
    struct sched_param param;

    pthread_attr_init(&attr);

    if ((attr = pthread_attr_getschedpolicy(&attr)) == -1) {
        perror("pthread_attr_setschedpolicy");
        exit(EXIT_FAILURE);
    }

    param.sched_priority = 10;
    if (pthread_attr_setschedparam(&attr, &param) != 0) {
        perror("pthread_attr_setschedparam");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&thread, &attr, thread_function, NULL) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    if (pthread_attr_getschedpolicy(&attr, &policy) != 0) {
        perror("pthread_attr_getschedpolicy");
        exit(EXIT_FAILURE);
    }

    switch (policy) {
        case SCHED_FIFO:
            printf("Current policy is SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current policy is SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("Current policy is SCHED_OTHER\n");
            break;
        default:
            printf("Unknown scheduling policy\n");
            break;
    }

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    // Clean up
    pthread_attr_destroy(&attr);

    return 0;
}
