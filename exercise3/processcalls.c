#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  printf("1. PARENT: My process ID is %d\n", getpid());

  int pid = fork();

  if (pid < 0) {
    printf("Fork failed!\n");
    exit(1);
  } else if (pid == 0) {
    printf("2. CHILD: I am alive! My process ID is %d\n", getpid());
    printf("   CHILD: Closing my standard input...\n");
    close(0);
    printf("   CHILD: My work is done. Exiting now.\n");
    exit(0);
  } else {
    printf("3. PARENT: I created a child with PID %d. I will wait for it to "
           "finish.\n",
           pid);
    wait(NULL);
    printf("4. PARENT: My child has finished. I will exit now too.\n");
  }

  return 0;
}