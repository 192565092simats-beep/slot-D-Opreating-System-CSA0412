/*
 * Experiment 19: Reader-Writer Problem using Semaphores
 * Aim: Construct a C program to simulate Reader-Writer problem using semaphores.
 */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex_sem, writeBlock;
int data = 100, readersCount = 0;

void *reader(void *arg) {
    int id = *(int *)arg;
    sem_wait(&mutex_sem);
    readersCount++;
    if (readersCount == 1) sem_wait(&writeBlock);
    sem_post(&mutex_sem);

    printf("Reader %d is reading data: %d (Active Readers: %d)\n", id, data, readersCount);
    usleep(10000);

    sem_wait(&mutex_sem);
    readersCount--;
    if (readersCount == 0) sem_post(&writeBlock);
    sem_post(&mutex_sem);
    return NULL;
}

void *writer(void *arg) {
    int id = *(int *)arg;
    sem_wait(&writeBlock);
    data += 10;
    printf("Writer %d updated data to: %d\n", id, data);
    sem_post(&writeBlock);
    return NULL;
}

int main() {
    pthread_t r1, r2, w1, r3;
    int id1 = 1, id2 = 2, id3 = 3;
    sem_init(&mutex_sem, 0, 1);
    sem_init(&writeBlock, 0, 1);

    pthread_create(&r1, NULL, reader, &id1);
    pthread_create(&r2, NULL, reader, &id2);
    pthread_create(&w1, NULL, writer, &id1);
    pthread_create(&r3, NULL, reader, &id3);

    pthread_join(r1, NULL); pthread_join(r2, NULL);
    pthread_join(w1, NULL); pthread_join(r3, NULL);

    sem_destroy(&mutex_sem); sem_destroy(&writeBlock);
    return 0;
}
