#include <stdio.h>
#include <stdbool.h>

// Helper to check if page is already in frames
bool isHit(int page, int frames[], int f_count) {
    for (int i = 0; i < f_count; i++) {
        if (frames[i] == page) return true;
    }
    return false;
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int n = sizeof(pages) / sizeof(pages[0]);
    int f_count = 3; // Number of frames
    int frames[f_count];
    
    // Initialize frames to -1 (empty)
    for (int i = 0; i < f_count; i++) frames[i] = -1;
    
    int faults = 0;
    int index = 0; // Tracks the oldest page
    
    printf("--- FIFO PAGE REPLACEMENT ---\n");
    
    for (int i = 0; i < n; i++) {
        if (!isHit(pages[i], frames, f_count)) {
            // Page fault: replace the oldest page
            frames[index] = pages[i];
            index = (index + 1) % f_count; // Move to the next oldest position
            faults++;
        }
    }
    
    printf("Total Page Faults: %d\n", faults);
    return 0;
}
