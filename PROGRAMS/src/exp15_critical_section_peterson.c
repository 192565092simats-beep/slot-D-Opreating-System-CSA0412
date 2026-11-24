/*
 * Experiment 15: Process Synchronization (Peterson's Algorithm)
 * Aim: Solve critical section problem using Peterson's mutual exclusion algorithm.
 */
#include <stdio.h>

int flag[2] = {0, 0};
int turn = 0;

void process0(void) {
    flag[0] = 1;
    turn = 1;
    while (flag[1] && turn == 1) {
        /* Waiting */
        break;
    }
    printf("Process 0 enters critical section\n");
    printf("Process 0 exits critical section\n");
    flag[0] = 0;
}

void process1(void) {
    flag[1] = 1;
    turn = 0;
    while (flag[0] && turn == 0) {
        /* Waiting */
        break;
    }
    printf("Process 1 enters critical section\n");
    printf("Process 1 exits critical section\n");
    flag[1] = 0;
}

int main() {
    process0();
    process1();
    process0();
    process1();
    return 0;
}
