/*
 * Experiment 20: Dining Philosophers Problem Simulation
 * Aim: Design a C program to simulate the Dining Philosophers synchronization problem.
 */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5
sem_t chopstick[N];

void *philosopher(void *num) {
    int id = *(int *)num;
    printf("Philosopher %d is thinking...\n", id);
    usleep(10000);

    // Deadlock-free asymmetric pickup strategy
    if (id % 2 == 0) {
        sem_wait(&chopstick[id]);
        sem_wait(&chopstick[(id + 1) % N]);
    } else {
        sem_wait(&chopstick[(id + 1) % N]);
        sem_wait(&chopstick[id]);
    }

    printf("Philosopher %d picked up chopsticks and is EATING\n", id);
    usleep(20000);

    sem_post(&chopstick[id]);
    sem_post(&chopstick[(id + 1) % N]);
    printf("Philosopher %d put down chopsticks and finished eating\n", id);
    return NULL;
}

int main() {
    pthread_t phil[N];
    int ids[N];
    for (int i = 0; i < N; i++) sem_init(&chopstick[i], 0, 1);
    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&phil[i], NULL, philosopher, &ids[i]);
    }
    for (int i = 0; i < N; i++) pthread_join(phil[i], NULL);
    for (int i = 0; i < N; i++) sem_destroy(&chopstick[i]);
    return 0;
}
