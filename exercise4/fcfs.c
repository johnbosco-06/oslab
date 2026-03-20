#include <stdio.h>

int main() {
    int at[] = {0, 1, 2, 4}, bt[] = {5, 3, 8, 6}, n = 4, ct = 0, tat, wt;
    float t_tat = 0, t_wt = 0;

    printf("P\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        if (ct < at[i]) ct = at[i]; // Handles CPU idle time
        ct += bt[i];
        tat = ct - at[i];
        wt = tat - bt[i];
        t_tat += tat; 
        t_wt += wt;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct, tat, wt);
    }
    printf("\nAvg TAT: %.2f | Avg WT: %.2f\n", t_tat/n, t_wt/n);
    return 0;
}
