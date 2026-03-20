#include <stdio.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <unistd.h>

struct msg_buffer {
  long type;
  char text[50];
} msg;

int main() {
  int msgid = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);

  if (fork() == 0) {
    msg.type = 1;
    strcpy(msg.text, "Hello via Message Queue!");
    msgsnd(msgid, &msg, sizeof(msg.text), 0);
  } else {
    wait(NULL);
    msgrcv(msgid, &msg, sizeof(msg.text), 1, 0);
    printf("Parent Read: %s\n", msg.text);

    msgctl(msgid, IPC_RMID, NULL);
  }

  return 0;
}