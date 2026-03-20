#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int fd[2];
  char buffer[50];

  pipe(fd);

  if (fork() == 0) {
    write(fd[1], "Hello via Pipe!", 16);
  } else {
    wait(NULL);
    read(fd[0], buffer, sizeof(buffer));
    printf("Parent Read: %s\n", buffer);
  }

  return 0;
}