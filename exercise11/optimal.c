#include <stdio.h>
#include <stdbool.h>

bool isHit(int page, int frames[], int f_count) {
    for (int i = 0; i < f_count; i++) {
        if (frames[i] == page) return true;
    }
    return false;
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int n = sizeof(pages) / sizeof(pages[0]);
    int f_count = 3;
    int frames[f_count];
    
    for (int i = 0; i < f_count; i++) frames[i] = -1;
    
    int faults = 0;
    
    printf("--- OPTIMAL PAGE REPLACEMENT ---\n");
    
    for (int i = 0; i < n; i++) {
        if (!isHit(pages[i], frames, f_count)) {
            int replace_index = -1;
            int farthest = i;
            
            // Find which frame to replace by looking ahead
            for (int j = 0; j < f_count; j++) {
                if (frames[j] == -1) {
                    replace_index = j; // Empty frame takes priority
                    break;
                }
                
                int k;
                for (k = i + 1; k < n; k++) {
                    if (frames[j] == pages[k]) {
                        if (k > farthest) {
                            farthest = k;
                            replace_index = j;
                        }
                        break;
                    }
                }
                // If a page in the frame is never referenced again
                if (k == n) { 
                    replace_index = j;
                    break;
                }
            }
            
            frames[replace_index] = pages[i];
            faults++;
        }
    }
    
    printf("Total Page Faults: %d\n", faults);
    return 0;
}
