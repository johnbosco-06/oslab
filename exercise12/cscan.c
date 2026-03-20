#include <stdio.h>
#include <stdlib.h>

#define DISK_SIZE 200

// Helper function to sort the array
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int requests[] = {82, 170, 43, 140, 24, 16, 190};
    int n = sizeof(requests) / sizeof(requests[0]);
    int head = 50; 
    int total_movement = 0;
    
    // Array holds requests + head + both boundaries
    int arr[n + 3];
    for (int i = 0; i < n; i++) arr[i] = requests[i];
    
    // Add boundaries for circular scanning
    arr[n] = head;
    arr[n + 1] = DISK_SIZE - 1; // High end
    arr[n + 2] = 0;             // Low end
    
    sort(arr, n + 3);
    
    // Locate the starting position of the head
    int head_idx;
    for (int i = 0; i < n + 3; i++) {
        if (arr[i] == head) { 
            head_idx = i; 
            break; 
        }
    }
    
    printf("--- C-SCAN DISK SCHEDULING ---\n");
    printf("Initial Head Position: %d\n", head);
    
    // 1. Move Right to the very end of the disk
    for (int i = head_idx; i < n + 2; i++) {
        total_movement += abs(arr[i + 1] - arr[i]);
    }
    
    // 2. Jump from the high end back to track 0
    total_movement += abs(arr[n + 2] - arr[0]);
    
    // 3. Move Right from 0 up to the last request before the original head
    for (int i = 0; i < head_idx - 1; i++) {
        total_movement += abs(arr[i + 1] - arr[i]);
    }
    
    printf("Total Head Movement: %d\n", total_movement);
    return 0;
}
