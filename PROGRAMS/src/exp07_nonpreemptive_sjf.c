/*
 * Experiment 7: Non-preemptive Shortest Job First (SJF) CPU Scheduling
 * Aim: Implement non-preemptive SJF CPU scheduling.
 */
#include <stdio.h>

int main() {
    int n, i, j, bt[10], p[10], wt[10], tat[10], temp;
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    if (scanf("%d", &n) != 1) return 1;

    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter burst time for P%d: ", i + 1);
        if (scanf("%d", &bt[i]) != 1) return 1;
    }

    // Sort based on burst time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
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
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage WT = %.2f\n", avgwt / n);
    printf("Average TAT = %.2f\n", avgtat / n);
    return 0;
}
