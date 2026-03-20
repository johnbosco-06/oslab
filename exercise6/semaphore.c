#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Shared resource
int shared_counter = 0;

// Declare the semaphore
sem_t mutex;

// Thread function
void* thread_function(void* arg) {
    int thread_id = *(int*)arg;

    printf("Thread %d: Waiting to enter critical section...\n", thread_id);
    
    // Wait (decrement) the semaphore. 
    // If it's 0, the thread blocks until another thread posts.
    sem_wait(&mutex); 
    
    // --- CRITICAL SECTION BEGIN ---
    printf("Thread %d: Entered critical section.\n", thread_id);
    
    // Read the shared counter, increment it, and write it back
    int local_copy = shared_counter;
    local_copy++;
    
    // Simulate some processing time to increase the chance of race conditions 
    // (if the semaphore weren't protecting it)
    sleep(1); 
    
    shared_counter = local_copy;
    printf("Thread %d: Incremented shared_counter to %d.\n", thread_id, shared_counter);
    // --- CRITICAL SECTION END ---

    printf("Thread %d: Leaving critical section.\n", thread_id);
    
    // Post (increment) the semaphore, waking up any waiting threads.
    sem_post(&mutex); 

    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int id1 = 1;
    int id2 = 2;

    // Initialize the semaphore
    // 2nd argument: 0 means the semaphore is shared between threads of the process
    // 3rd argument: 1 is the initial value (1 allows it to act as a mutual exclusion lock)
    if (sem_init(&mutex, 0, 1) != 0) {
        perror("Semaphore initialization failed");
        exit(EXIT_FAILURE);
    }

    // Create two threads
    if (pthread_create(&thread1, NULL, thread_function, &id1) != 0) {
        perror("Failed to create thread 1");
        exit(EXIT_FAILURE);
    }
    
    if (pthread_create(&thread2, NULL, thread_function, &id2) != 0) {
        perror("Failed to create thread 2");
        exit(EXIT_FAILURE);
    }

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy the semaphore to free resources
    sem_destroy(&mutex);

    printf("Main: Both threads finished. Final shared_counter value = %d\n", shared_counter);

    return 0;
}
