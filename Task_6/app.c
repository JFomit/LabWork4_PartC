#include "ctoast/io.h"
#include "lr/task_6.h"
#include <stdio.h>

void MakeMagicSquare(int *_) {
  long n = 0;
  printf("Введите порядок квадрата:\n");
  if (!ReadLong(&n) || n <= 0) {
    printf("Размер квадрата должен быть неотрицательным.\n");
    goto out;
  }
  // trivial cases
  if (n == 1) {
    printf("1\n");
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

  if (n > 46340) {
    printf("ВНИМАНИЕ: запрошенный размер квадрата вызовет переполениение его "
           "элементов!\n");
  }

  void (*constructors[4])(Matrix_t *) = {&EvenEvenSquare, &OddSquare,
                                         &EvenOddSquare, &OddSquare};

  constructors[n % 4](&matrix);

  for (long i = 0; i < n; ++i) {
    for (long j = 0; j < n; ++j) {
      printf("%i ", *At(&matrix, i, j));
    }
    printf("\n");
  }

cleanup:
  FreeMatrix(&matrix);
out:
  return;
}

void OddSquareInSlice(Matrix_t *matrix, long n) {
  long n_2 = n * n;

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

void OddSquare(Matrix_t *matrix) {
  long n = matrix->n;
  OddSquareInSlice(matrix, n);
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

void Swap(int *a, int *b) {
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}

void EvenOddSquare(Matrix_t *matrix) {
  long n = matrix->n;
  long m = n / 2;
  long m_2 = m * m;

  // Step 1:
  // Let M1, M2, M3, and M4 represent magic squares of order n (sub matricies)
  //
  // M1   M2
  //
  // M3   M4
  //
  OddSquareInSlice(matrix, m); // M1

  for (long i = 0; i < m; ++i) {
    for (long j = 0; j < m; ++j) {
      int item = *At(matrix, i, j);

      *At(matrix, i, j + m) = item + 2 * (int)m_2; // M2
      *At(matrix, i + m, j) = item + 3 * (int)m_2; // M3
      *At(matrix, i + m, j + m) = item + (int)m_2; // M4
    }
  }

  long q = m - 3;
  // Swapping right q columns of M3 with q right columns of M1; the same for M4
  // & M2
  for (long j = m - q / 2; j < m + q / 2; ++j) {
    for (long i = 0; i < m; ++i) {
      int *a = At(matrix, i + m, j);
      int *b = At(matrix, i, j);
      Swap(a, b);
    }
  }

  // Swapping items in M1 & M3 by jagged line
  Swap(At(matrix, 0, 0), At(matrix, m, 0)); // first endpoint

  for (long i = 1; i < m - 1; ++i) {
    Swap(At(matrix, i, 1), At(matrix, i + m, 1));
  }

  Swap(At(matrix, m - 1, 0), At(matrix, n - 1, 0)); // second endpoint
}