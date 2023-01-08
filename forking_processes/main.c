#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int perform_factorial(int num) {
  return num == 1 ? 1 : num * perform_factorial(num - 1);
}

int main() {

  int input_number = 1;
  int scan_status = 0;

  while (1) {

    printf("Digite um número para calcular o fatorial:\n");
    scan_status = scanf("%d", &input_number);

    if (scan_status != 1) {
      printf("Valor informado é inválido!\n");
      continue;
    }

    pid_t process_pid = fork();

    int is_child_process = process_pid == 0 ? 1 : 0;

    if (is_child_process) {

      sleep(2);
      printf("O fatorial de %d é %d\n", input_number,
             perform_factorial(input_number));
      return 0;
    }
  }
}