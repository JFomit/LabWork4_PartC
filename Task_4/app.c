#include "ctoast/io.h"
#include "lr/task_4.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

size_t GetMaxSumDiagonalNo(long *cube, size_t n) {
  size_t n_2 = n * n;
  size_t up_n = n - 1;

  long diagonalic_sums[4] = {0, 0, 0, 0};
  for (size_t d = 0; d < n; ++d) {
    size_t i, j, k;
    i = d;
    j = d;
    k = d;
    diagonalic_sums[0] += ((long *)cube)[i * n_2 + j * n + k];

    i = up_n - d;
    j = d;
    k = d;
    diagonalic_sums[1] += ((long *)cube)[i * n_2 + j * n + k];

    i = d;
    j = up_n - d;
    k = d;
    diagonalic_sums[2] += ((long *)cube)[i * n_2 + j * n + k];

    i = up_n - d;
    j = up_n - d;
    k = d;
    diagonalic_sums[3] += ((long *)cube)[i * n_2 + j * n + k];
  }

  long max = diagonalic_sums[0];
  size_t max_d = 0;
  for (size_t d = 0; d < 4; ++d) {
    if (diagonalic_sums[d] > max) {
      max = diagonalic_sums[d];
      max_d = d;
    }
  }

  return max_d;
}

void Run(int *_) {
  printf("Введите n:");
  long input = 0;
  if (!ReadLong(&input) || input <= 0) {
    printf("Ожидалось целое положительное число.");
    goto out;
  }

  size_t n = (size_t)input;
  size_t n_2 = n * n;
  size_t n_3 = n_2 * n;
  long *array = (long *)malloc(n_3 * sizeof(long));
  if (!array) {
    goto cleanup;
  }
  if (!ReadArray(array, n_3)) {
    goto cleanup;
  }

  size_t max_d = GetMaxSumDiagonalNo(array, n);

  printf("Наибольшая диагональ: номер %li\n", max_d + 1);

  for (size_t d = 0; d < n; ++d) {
    size_t i, j, k;
    switch (max_d) {
    case 0:
      i = d;
      j = d;
      k = d;
      break;
    case 1:
      i = n - d;
      j = d;
      k = d;
      break;
    case 2:
      i = d;
      j = n - d;
      k = d;
      break;
    case 3:
      i = n - d;
      j = n - d;
      k = d;
      break;
    }

    printf("%li ", array[i * n_2 + j * n + k]);
  }

cleanup:
  free(array);
out:
  return;
}
