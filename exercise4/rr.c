#include <stdio.h>

int main() {
    int p[] = {1, 2, 3, 4}, at[] = {0, 1, 2, 4}, bt[] = {5, 3, 8, 6}, rem[] = {5, 3, 8, 6};
    int n = 4, q = 2, ct = 0, done = 0, tat, wt, flag;
    float t_tat = 0, t_wt = 0;

    printf("P\tAT\tBT\tCT\tTAT\tWT\n");
    while (done < n) {
        flag = 0;
        for (int i = 0; i < n; i++) {
            if (at[i] <= ct && rem[i] > 0) {
                flag = 1;
                int step = (rem[i] > q) ? q : rem[i];
                ct += step;
                rem[i] -= step;
                
                if (rem[i] == 0) {
                    done++;
                    tat = ct - at[i];
                    wt = tat - bt[i];
                    t_tat += tat; t_wt += wt;
                    printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct, tat, wt);
                }
            }
        }
        if (!flag) ct++; // CPU Idle
    }
    printf("\nAvg TAT: %.2f | Avg WT: %.2f\n", t_tat/n, t_wt/n);
    return 0;
}