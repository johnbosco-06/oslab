#include <stdio.h>

int main() {
    int p[] = {1, 2, 3, 4}, at[] = {0, 1, 2, 4}, bt[] = {5, 3, 8, 6}, pr[] = {3, 1, 4, 2}, done[4] = {0};
    int n = 4, ct = 0, completed = 0, tat, wt;
    float t_tat = 0, t_wt = 0;

    printf("P\tPR\tAT\tBT\tCT\tTAT\tWT\n");
    while (completed < n) {
        int idx = -1, min_pr = 9999; // Lower number = stronger priority
        for (int i = 0; i < n; i++) {
            if (at[i] <= ct && !done[i] && pr[i] < min_pr) {
                min_pr = pr[i];
                idx = i;
            }
        }
        if (idx != -1) {
            ct += bt[idx];
            tat = ct - at[idx];
            wt = tat - bt[idx];
            t_tat += tat; t_wt += wt;
            done[idx] = 1;
            completed++;
            printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[idx], pr[idx], at[idx], bt[idx], ct, tat, wt);
        } else {
            ct++; // CPU idle
        }
    }
    printf("\nAvg TAT: %.2f | Avg WT: %.2f\n", t_tat/n, t_wt/n);
    return 0;
}