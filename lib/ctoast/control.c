#include "ctoast/control.h"
#include "ctoast/io.h"
#include <stdio.h>

void Loop(int *should_close, RunnerFunction runner) {
  char option;

  printf("~> ");
  if (!ReadCharFromLine(&option)) {
    printf("Ожидался символ; введите `h' для справки.");
    return;
  }

  switch (option) {
  case 'h':
    printf("r - Запуск\nq - Выход\nh - Эта справка\n");
    return;
  case 'q':
    *should_close = 1;
    return;
  case 'r':
    runner(should_close);
    return;
  default:
    printf("Неизвестная опция - %c; введите `h' для справки.\n", option);
    return;
  }
}