#include <stdio.h>
#include <unistd.h>

int main() {

  char *const command[] = {"cat", "./main.c", NULL};

  if (fork() == 0) {
    printf("Imprimindo o código fonte desse programa\n");
    execvp(command[0], command);
    printf("Processo filho\n");
  } else {
    printf("Processo pai\n");
  }
  printf("Fim\n");

  return 0;
}