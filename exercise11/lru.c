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
    int time[f_count]; // To track the 'time' of last access
    
    for (int i = 0; i < f_count; i++) frames[i] = -1;
    
    int faults = 0;
    
    printf("--- LRU PAGE REPLACEMENT ---\n");
    
    for (int i = 0; i < n; i++) {
        if (!isHit(pages[i], frames, f_count)) {
            int lru_index = 0;
            
            // Find empty frame or the least recently used frame
            for (int j = 1; j < f_count; j++) {
                if (frames[j] == -1) {
                    lru_index = j;
                    break; // Empty frame found
                }
                if (time[j] < time[lru_index]) {
                    lru_index = j; // Update to older frame
                }
            }
            
            frames[lru_index] = pages[i];
            time[lru_index] = i; // Mark the 'time' of insertion/update
            faults++;
        } else {
            // It's a hit, so we just need to update its recently used time
            for (int j = 0; j < f_count; j++) {
                if (frames[j] == pages[i]) {
                    time[j] = i;
                    break;
                }
            }
        }
    }
    
    printf("Total Page Faults: %d\n", faults);
    return 0;
}
