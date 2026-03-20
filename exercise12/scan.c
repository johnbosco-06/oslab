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
    
    // Create an array large enough to hold requests + head + boundary
    int arr[n + 2];
    for (int i = 0; i < n; i++) arr[i] = requests[i];
    
    // Add the head and the end of the disk to the array
    arr[n] = head;
    arr[n + 1] = DISK_SIZE - 1; 
    
    sort(arr, n + 2);
    
    // Locate the starting position of the head in the sorted array
    int head_idx;
    for (int i = 0; i < n + 2; i++) {
        if (arr[i] == head) { 
            head_idx = i; 
            break; 
        }
    }
    
    printf("--- SCAN DISK SCHEDULING ---\n");
    printf("Initial Head Position: %d\n", head);
    
    // 1. Move Right to the end of the disk
    for (int i = head_idx; i < n + 1; i++) {
        total_movement += abs(arr[i + 1] - arr[i]);
    }
    
    // 2. Jump to the closest left element from the end
    if (head_idx > 0) {
        total_movement += abs(arr[n + 1] - arr[head_idx - 1]);
    }
    
    // 3. Move Left servicing remaining requests
    for (int i = head_idx - 1; i > 0; i--) {
        total_movement += abs(arr[i] - arr[i - 1]);
    }
    
    printf("Total Head Movement: %d\n", total_movement);
    return 0;
}
