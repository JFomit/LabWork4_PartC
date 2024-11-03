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

    long old_i = i;
    long old_j = j;
    i = i == 0 ? n - 1 : i - 1;
    j = (j + 1) % n;

    if (*At(matrix, i, j) != 0) {
      i = old_i;
      j = old_j;

      i += 1;
    }
  }
}

void EvenEvenSquare(Matrix_t *matrix) {
  long n = matrix->n;
  long n_2 = n * n;
  long n_over_4 = n / 4;
  long three_n_over_4 = 3 * (n / 4);
  // fill array with their index-counting
  // starting from 1
  for (long d = 0; d < n_2; ++d) {
    matrix->array[d] = (int)d + 1;
  }

  // change value of Array elements
  // at fix location as per rule
  // (n*n+1)-arr[i][j]
  // Top Left corner of Matrix
  // (order (n/4)*(n/4))
  for (long i = 0; i < n_over_4; ++i) {
    for (long j = 0; j < n_over_4; ++j)
      *At(matrix, i, j) = (int)((n_2 + 1) - *At(matrix, i, j));
  }

  // Top Right corner of Matrix
  // (order (n/4)*(n/4))
  for (long i = 0; i < n_over_4; ++i) {
    for (long j = three_n_over_4; j < n; ++j)
      *At(matrix, i, j) = (int)((n_2 + 1) - *At(matrix, i, j));
  }

  // Bottom Left corner of Matrix
  // (order (n/4)*(n/4))
  for (long i = three_n_over_4; i < n; ++i) {
    for (long j = 0; j < n_over_4; ++j)
      *At(matrix, i, j) = (int)((n_2 + 1) - *At(matrix, i, j));
  }

  // Bottom Right corner of Matrix
  // (order (n/4)*(n/4))
  for (long i = three_n_over_4; i < n; ++i) {
    for (long j = three_n_over_4; j < n; ++j)
      *At(matrix, i, j) = (int)((n_2 + 1) - *At(matrix, i, j));
  }

  // Centre of Matrix (order (n/2)*(n/2))
  for (long i = n_over_4; i < three_n_over_4; ++i) {
    for (long j = n_over_4; j < three_n_over_4; ++j)
      *At(matrix, i, j) = (int)((n_2 + 1) - *At(matrix, i, j));
  }
}