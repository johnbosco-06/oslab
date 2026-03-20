#include <stdio.h>

int main() {
    int blocks[] = {100, 500, 200, 300, 600};
    int processes[] = {212, 417, 112, 426};
    int b_count = sizeof(blocks) / sizeof(blocks[0]);
    int p_count = sizeof(processes) / sizeof(processes[0]);
    int allocation[p_count];

    // Initialize allocations to -1
    for (int i = 0; i < p_count; i++) allocation[i] = -1;

    for (int i = 0; i < p_count; i++) {
        int worst_idx = -1;
        for (int j = 0; j < b_count; j++) {
            if (blocks[j] >= processes[i]) {
                if (worst_idx == -1 || blocks[j] > blocks[worst_idx]) {
                    worst_idx = j; // Update with a larger fitting block
                }
            }
        }
        if (worst_idx != -1) {
            allocation[i] = worst_idx;
            blocks[worst_idx] -= processes[i];
        }
    }

    printf("\n--- WORST FIT ALLOCATION ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < p_count; i++) {
        printf(" %d\t\t%d\t\t", i + 1, processes[i]);
        if (allocation[i] != -1) printf("%d\n", allocation[i] + 1);
        else printf("Not Allocated\n");
    }

    return 0;
}
