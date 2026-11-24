/*
 * Experiment 3: Producer-Consumer Problem using POSIX Semaphores
 * Aim: Simulate the classic producer-consumer synchronization using semaphores.
 */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define SIZE 5
int buffer[SIZE];
int item = 0;
sem_t empty_sem, full_sem, mutex_sem;

void *producer(void *arg) {
    (void)arg;
    for (int i = 1; i <= 5; i++) {
        sem_wait(&empty_sem);
        sem_wait(&mutex_sem);
        buffer[item++] = i;
        printf("Produced: %d\n", i);
        sem_post(&mutex_sem);
        sem_post(&full_sem);
    }
    return NULL;
}

void *consumer(void *arg) {
    (void)arg;
    for (int i = 1; i <= 5; i++) {
        sem_wait(&full_sem);
        sem_wait(&mutex_sem);
        int consumed_val = buffer[--item];
        printf("Consumed: %d\n", consumed_val);
        sem_post(&mutex_sem);
        sem_post(&empty_sem);
    }
    return NULL;
}

int main() {
    pthread_t prod, cons;
    sem_init(&empty_sem, 0, SIZE);
    sem_init(&full_sem, 0, 0);
    sem_init(&mutex_sem, 0, 1);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    sem_destroy(&empty_sem);
    sem_destroy(&full_sem);
    sem_destroy(&mutex_sem);
    return 0;
}
