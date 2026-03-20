#include <stdio.h>

int main() {
  int at[] = {0, 1, 2, 4}, bt[] = {5, 3, 8, 6}, done[4] = {0}, n = 4, ct = 0,
      c = 0;
  float ttat = 0, twt = 0;

  printf("P\tAT\tBT\tCT\tTAT\tWT\n");
  while (c < n) {
    int idx = -1, min = 9999;
    for (int i = 0; i < n; i++)
      if (at[i] <= ct && !done[i] && bt[i] < min) {
        min = bt[i];
        idx = i;
      }

    if (idx != -1) {
      ct += bt[idx];
      done[idx] = 1;
      c++;
      ttat += ct - at[idx];
      twt += ct - at[idx] - bt[idx];
      printf("%d\t%d\t%d\t%d\t%d\t%d\n", idx + 1, at[idx], bt[idx], ct,
             ct - at[idx], ct - at[idx] - bt[idx]);
    } else
      ct++;
  }
  printf("\nAvg TAT: %.2f | Avg WT: %.2f\n", ttat / n, twt / n);
  return 0;
}