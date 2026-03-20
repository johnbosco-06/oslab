#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int requests[] = {82, 170, 43, 140, 24, 16, 190};
    int n = sizeof(requests) / sizeof(requests[0]);
    int head = 50; 
    
    bool visited[n];
    for(int i = 0; i < n; i++) visited[i] = false;
    
    int total_movement = 0;
    int current = head;
    
    printf("--- SSTF DISK SCHEDULING ---\n");
    printf("Initial Head Position: %d\n", head);
    
    for (int i = 0; i < n; i++) {
        int min_dist = 9999;
        int index = -1;
        
        // Find the closest unvisited request
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int dist = abs(current - requests[j]);
                if (dist < min_dist) {
                    min_dist = dist;
                    index = j;
                }
            }
        }
        
        visited[index] = true;
        total_movement += min_dist;
        current = requests[index]; // Move head to the new position
    }
    
    printf("Total Head Movement: %d\n", total_movement);
    return 0;
}
