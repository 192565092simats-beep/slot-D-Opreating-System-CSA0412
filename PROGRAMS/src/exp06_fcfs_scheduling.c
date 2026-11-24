/*
 * Experiment 6: First Come First Served (FCFS) CPU Scheduling
 * Aim: Design a CPU scheduling program in C using First Come First Served technique.
 */
#include <stdio.h>

int main() {
    int n, i, bt[10], wt[10], tat[10];
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    if (scanf("%d", &n) != 1) return 1;

    for (i = 0; i < n; i++) {
        printf("Enter burst time for P%d: ", i + 1);
        if (scanf("%d", &bt[i]) != 1) return 1;
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avgwt += wt[i];
        avgtat += tat[i];
    }

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage WT = %.2f\n", avgwt / n);
    printf("Average TAT = %.2f\n", avgtat / n);
    return 0;
}
