#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int shmid = shmget(IPC_PRIVATE, 1024, 0666 | IPC_CREAT);
  char *shared_mem = shmat(shmid, NULL, 0);

  if (fork() == 0) {
    strcpy(shared_mem, "Hello via Shared Memory!");
  } else {
    wait(NULL);
    printf("Parent Read: %s\n", shared_mem);

    shmdt(shared_mem);
    shmctl(shmid, IPC_RMID, NULL);
  }

  return 0;
}