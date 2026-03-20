#include <stdio.h>
#include <stdlib.h>

int main() {
    int requests[] = {82, 170, 43, 140, 24, 16, 190};
    int n = sizeof(requests) / sizeof(requests[0]);
    int head = 50; // Initial head position
    int total_movement = 0;
    
    printf("--- FCFS DISK SCHEDULING ---\n");
    printf("Initial Head Position: %d\n", head);
    
    int current = head;
    for (int i = 0; i < n; i++) {
        total_movement += abs(current - requests[i]);
        current = requests[i];
    }
    
    printf("Total Head Movement: %d\n", total_movement);
    return 0;
}
