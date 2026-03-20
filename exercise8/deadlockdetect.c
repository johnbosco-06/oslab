#include <stdio.h>
#include <stdbool.h>

int main() {
    int n = 5; // Number of processes
    int r = 3; // Number of resources

    // Allocation Matrix
    int alloc[5][3] = { { 0, 1, 0 },
                        { 2, 0, 0 },
                        { 3, 0, 3 },
                        { 2, 1, 1 },
                        { 0, 0, 2 } };

    // Request Matrix (Current requested resources by processes)
    int request[5][3] = { { 0, 0, 0 },
                          { 2, 0, 2 },
                          { 0, 0, 0 },
                          { 1, 0, 0 },
                          { 0, 0, 2 } };

    // Available Resources
    int avail[3] = { 0, 0, 0 };

    bool finish[n];
    int work[r];

    // Initialize Work = Available
    for (int i = 0; i < r; i++) {
        work[i] = avail[i];
    }

    // Initialize Finish: true if allocation is 0, else false
    for (int i = 0; i < n; i++) {
        bool has_alloc = false;
        for (int j = 0; j < r; j++) {
            if (alloc[i][j] != 0) {
                has_alloc = true;
                break;
            }
        }
        finish[i] = !has_alloc;
    }

    printf("--- DEADLOCK DETECTION ALGORITHM ---\n");

    // Detection loop
    bool found;
    do {
        found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool can_satisfy = true;
                for (int j = 0; j < r; j++) {
                    if (request[i][j] > work[j]) {
                        can_satisfy = false;
                        break;
                    }
                }
                
                if (can_satisfy) {
                    // Assume process finishes and returns resources
                    for (int j = 0; j < r; j++) {
                        work[j] += alloc[i][j];
                    }
                    finish[i] = true;
                    found = true;
                }
            }
        }
    } while (found);

    // Check results
    bool is_deadlock = false;
    for (int i = 0; i < n; i++) {
        if (!finish[i]) {
            is_deadlock = true;
            break;
        }
    }

    if (is_deadlock) {
        printf("Deadlock Detected! The following processes are deadlocked:\n");
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                printf("P%d ", i);
            }
        }
        printf("\n");
    } else {
        printf("No Deadlock Detected. All processes can finish successfully.\n");
    }

    return 0;
}
