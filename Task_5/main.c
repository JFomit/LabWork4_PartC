#include "ctoast/control.h"
#include "ctoast/io.h"
#include "lr/task_5.h"
#include <stdio.h>

void DoMinesweeper(int *);

int main(void) {
  PrintGreeting(
      5, "Вводит поле для игры в `сапёр' и заполняет это поле числами. Формат "
         "ввода: размеры m и n, пустая клетка - `.', бомба - `*'.\nДля опций "
         "введите `h'.");

  int should_close = 0;
  while (!should_close) {
    Loop(&should_close, &DoMinesweeper);
  }

  return 0;
}

void DoMinesweeper(int *_) {
  long m, n = 0;

  printf("Введите размеры поля m и n (через <Enter>):\n");
  if (!ReadLong(&m) || m <= 0 || !ReadLong(&n) || n <= 0) {
    (void)fprintf(stderr,
                  "Размеры поля должны быть положительными целыми числами.\n");
    return;
  }

  Field_t field;
  if (!AllocateField((size_t)m, (size_t)n, &field)) {
    (void)fprintf(stderr, "Не удалось аллоцировать поле.\n");
    goto cleanup;
  }
  printf("Введите поле для сапера размера %li на %li\n", m, n);
  if (!ReadProcessReportErr(&field)) {
    goto cleanup;
  }

  printf("Результирующий массив:\n");
  for (long i = 0; i < field.m; ++i) {
    for (long j = 0; j < field.n; ++j) {
      printf("%c ", *CellAt(&field, i, j));
    }
    printf("\n");
  }

cleanup:
  FreeField(&field);
}
