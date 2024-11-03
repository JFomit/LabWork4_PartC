#include "ctoast/result.h"
#include "lr/task_6.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *At(Matrix_t *matrix, long i, long j) {
  long n = matrix->n;
  int *array = matrix->array;
  if (i < 0 || i >= n || j < 0 || j >= n) {
    return NULL;
  }

  return &array[i * n + j];
}
Result_t AllocateMatrix(Matrix_t *matrix, long n) {
  int *backing_array = (int *)malloc((size_t)n * (size_t)n * sizeof(int));
  if (!backing_array) {
    matrix->array = NULL;
    matrix->n = n;
    return kErr;
  }
  memset(backing_array, 0, (size_t)n * (size_t)n * sizeof(int));
  matrix->array = backing_array;
  matrix->n = n;

  return kOk;
}
void FreeMatrix(Matrix_t *matrix) {
  free(matrix->array);
  matrix->array = NULL;
  matrix->n = 0;
}
