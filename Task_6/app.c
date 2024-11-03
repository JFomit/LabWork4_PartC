#include "ctoast/io.h"
#include "lr/task_6.h"
#include <stdio.h>

void MakeMagicSquare(int *_) {
  long n = 0;
  if (!ReadLong(&n) || n <= 0) {
    printf("Размер квадрата должен быть неотрицательным.\n");
    goto out;
  }
  // trivial cases
  if (n == 1) {
    printf("1");
    goto out;
  }
  if (n == 2) {
    printf("Не существует магического квадрата 2 на 2.\n");
    goto out;
  }

  // Non-trivial cases
  Matrix_t matrix;
  if (!AllocateMatrix(&matrix, n)) {
    printf("Не удалось выделить достаточно памяти. Запрошено %li байт.\n",
           n * n * (long)sizeof(int));
    goto cleanup;
  }

cleanup:
  FreeMatrix(&matrix);
out:
  return;
}

void OddSquare(Matrix_t *matrix) {
  long n_2 = matrix->n * matrix->n;
  long n = matrix->n;

  long i = 0;
  long j = (n - 1) / 2;
  for (int d = 1; d <= n_2; ++d) {
    *At(matrix, i, j) = d;

    i = i == 0 ? n - 1 : i - 1;
    j = (j + 1) % n;

    int *ptr = At(matrix, i, j);
    while (!ptr && *ptr) {
      j = (j + 1) % n;
    }
  }
}