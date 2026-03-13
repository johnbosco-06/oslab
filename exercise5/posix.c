#include <pthread.h>
#include <stdio.h>

void *task(void *arg) {
  printf("Hello from Thread %ld!\n", (long)arg);
  return NULL;
}

int main() {
  pthread_t t1, t2;

  pthread_create(&t1, NULL, task, (void *)1);
  pthread_create(&t2, NULL, task, (void *)2);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  printf("All threads finished.\n");
  return 0;
}