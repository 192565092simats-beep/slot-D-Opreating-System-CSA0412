/*
 * Experiment 10: Preemptive Shortest Remaining Time First (SRTF) Scheduling
 * Aim: Simulate preemptive SJF scheduling algorithm with arrival time.
 */
#include <stdio.h>

int main() {
    int at[10], bt[10], rt[10], endTime, i, smallest;
    int remain = 0, n, time, sum_wait = 0, sum_turnaround = 0;

    printf("Enter number of Processes: ");
    if (scanf("%d", &n) != 1) return 1;

    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for P%d: ", i + 1);
        if (scanf("%d%d", &at[i], &bt[i]) != 2) return 1;
        rt[i] = bt[i];
    }

    rt[9] = 9999;
    for (time = 0; remain != n; time++) {
        smallest = 9;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] < rt[smallest] && rt[i] > 0) {
                smallest = i;
            }
        }
        rt[smallest]--;
        if (rt[smallest] == 0) {
            remain++;
            endTime = time + 1;
            sum_wait += endTime - bt[smallest] - at[smallest];
            sum_turnaround += endTime - at[smallest];
        }
    }

    printf("\nAverage Waiting Time = %.2f\n", (float)sum_wait / n);
    printf("Average Turnaround Time = %.2f\n", (float)sum_turnaround / n);
    return 0;
}
