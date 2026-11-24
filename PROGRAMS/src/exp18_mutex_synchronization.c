/*
 * Experiment 18: Process Synchronization using Mutex Locks
 * Aim: Design a C program to implement process synchronization using mutex locks.
 */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int counter = 0;
pthread_mutex_t lock;

void *worker(void *arg) {
    int id = *(int *)arg;
    for (int i = 0; i < 2; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        printf("Thread %d acquired lock: Counter = %d\n", id, counter);
        pthread_mutex_unlock(&lock);
        usleep(10000);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    pthread_mutex_init(&lock, NULL);
    printf("Starting Process Synchronization with Mutex...\n");

    pthread_create(&t1, NULL, worker, &id1);
    pthread_create(&t2, NULL, worker, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);
    printf("All threads finished. Final Counter = %d\n", counter);
    return 0;
}
