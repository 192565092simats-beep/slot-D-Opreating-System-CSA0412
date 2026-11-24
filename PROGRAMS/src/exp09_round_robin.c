/*
 * Experiment 9: Round Robin CPU Scheduling
 * Aim: Construct a C program to simulate Round Robin scheduling algorithm.
 */
#include <stdio.h>

int main() {
    int n, i, tq, sq = 0, bt[10], wt[10], tat[10], rem_bt[10];
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    if (scanf("%d", &n) != 1) return 1;

    printf("Enter burst time of processes:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        if (scanf("%d", &bt[i]) != 1) return 1;
        rem_bt[i] = bt[i];
    }

    printf("Enter time quantum: ");
    if (scanf("%d", &tq) != 1) return 1;

    while (1) {
        int done = 1;
        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;
                if (rem_bt[i] > tq) {
                    sq += tq;
                    rem_bt[i] -= tq;
                } else {
                    sq += rem_bt[i];
                    wt[i] = sq - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == 1) break;
    }

    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avgwt += wt[i];
        avgtat += tat[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", avgwt / n);
    printf("Average Turnaround Time = %.2f\n", avgtat / n);
    return 0;
}
