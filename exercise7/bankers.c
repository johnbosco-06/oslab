#include <stdio.h>

int main() {
    // Number of processes and resources
    int n = 5; // P0, P1, P2, P3, P4
    int r = 3; // A, B, C

    // Allocation Matrix: Resources currently allocated to each process
    int alloc[5][3] = { { 0, 1, 0 }, // P0
                        { 2, 0, 0 }, // P1
                        { 3, 0, 2 }, // P2
                        { 2, 1, 1 }, // P3
                        { 0, 0, 2 } }; // P4

    // Max Matrix: Maximum demand of each process
    int max[5][3] = { { 7, 5, 3 }, // P0
                      { 3, 2, 2 }, // P1
                      { 9, 0, 2 }, // P2
                      { 2, 2, 2 }, // P3
                      { 4, 3, 3 } }; // P4

    // Available Resources
    int avail[3] = { 3, 3, 2 };

    int f[n], ans[n], ind = 0;
    for (int k = 0; k < n; k++) {
        f[k] = 0; // Initialize finish array to 0 (false)
    }

    // Need Matrix: Need = Max - Allocation
    int need[n][r];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("--- BANKER'S ALGORITHM (DEADLOCK AVOIDANCE) ---\n");

    // Check for safe state
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < n; i++) {
            if (f[i] == 0) { // If process is not finished
                int flag = 0;
                for (int j = 0; j < r; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1; // Needs more than available
                        break;
                    }
                }

                if (flag == 0) {
                    // Safe to allocate, add allocated resources back to available
                    ans[ind++] = i;
                    for (int y = 0; y < r; y++) {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1; // Mark process as finished
                }
            }
        }
    }

    // Check if all processes were finished
    int isSafe = 1;
    for (int i = 0; i < n; i++) {
        if (f[i] == 0) {
            isSafe = 0;
            printf("System is NOT in a safe state. Deadlock may occur.\n");
            break;
        }
    }

    if (isSafe == 1) {
        printf("System is in a SAFE state.\nSafe Sequence: ");
        for (int i = 0; i < n - 1; i++) {
            printf("P%d -> ", ans[i]);
        }
        printf("P%d\n", ans[n - 1]);
    }

    return 0;
}
