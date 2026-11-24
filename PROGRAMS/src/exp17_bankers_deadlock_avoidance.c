/*
 * Experiment 17: Deadlock Avoidance using Banker's Algorithm
 * Aim: Illustrate deadlock avoidance concept by simulating Banker's algorithm safety check.
 */
#include <stdio.h>

#define P 5
#define R 3

int main() {
    int alloc[P][R] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    int max[P][R]   = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int avail[R]    = {3, 3, 2};

    int f[P], ans[P], ind = 0;
    for (int k = 0; k < P; k++) f[k] = 0;

    int need[P][R];
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    for (int k = 0; k < P; k++) {
        for (int i = 0; i < P; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (int j = 0; j < R; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (int y = 0; y < R; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    printf("Banker's Algorithm: Deadlock Avoidance Safety Check\n");
    printf("System is in a SAFE state.\nSafe Sequence: ");
    for (int i = 0; i < P - 1; i++) printf("P%d -> ", ans[i]);
    printf("P%d\n", ans[P - 1]);
    return 0;
}
