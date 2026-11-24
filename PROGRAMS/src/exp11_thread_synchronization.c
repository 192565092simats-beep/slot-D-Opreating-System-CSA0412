/*
 * Experiment 11: Multithreaded Computation & Thread Synchronization
 * Aim: Illustrate thread synchronization and parallel computation using POSIX threads.
 */
#include <stdio.h>
#include <pthread.h>

void *thread_sum(void *arg) {
    int id = *(int *)arg;
    int sum = 0;
    int start = (id == 1) ? 1 : 11;
    int end = (id == 1) ? 10 : 20;
    for (int i = start; i <= end; i++) {
        sum += i;
    }
    printf("Thread %d: Computed partial sum from %d to %d = %d\n", id, start, end, sum);
    return (void *)(long)sum;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;
    void *res1, *res2;

    printf("Main: Creating worker threads for parallel summation...\n");
    pthread_create(&t1, NULL, thread_sum, &id1);
    pthread_create(&t2, NULL, thread_sum, &id2);

    pthread_join(t1, &res1);
    pthread_join(t2, &res2);

    int total = (int)(long)res1 + (int)(long)res2;
    printf("Main: Worker threads joined successfully.\n");
    printf("Total Sum from 1 to 20 = %d\n", total);
    return 0;
}
