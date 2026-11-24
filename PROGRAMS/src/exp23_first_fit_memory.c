/*
 * Experiment 23: Memory Management: First Fit Algorithm
 * Aim: Construct a C program to implement the first fit algorithm of memory management.
 */
#include <stdio.h>

int main() {
    int bsize[10] = {100, 500, 200, 300, 600};
    int psize[10] = {212, 417, 112, 426};
    int m = 5, n = 4, allocation[10];

    for (int i = 0; i < n; i++) allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (bsize[j] >= psize[i]) {
                allocation[i] = j;
                bsize[j] -= psize[i];
                break;
            }
        }
    }

    printf("First Fit Memory Allocation\n\n");
    printf("Process No.\tProcess Size\tBlock No.\tRemaining Space\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, psize[i]);
        if (allocation[i] != -1)
            printf("%d\t\t%d\n", allocation[i] + 1, bsize[allocation[i]]);
        else
            printf("Not Allocated\t-\n");
    }
    return 0;
}
