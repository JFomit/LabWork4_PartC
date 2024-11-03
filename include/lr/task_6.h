#ifndef LR4_TASK_6_H_
#define LR4_TASK_6_H_

#include "ctoast/result.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef struct Matrix {
  int *array;
  long n;
} Matrix_t;

int *At(Matrix_t *matrix, long i, long j);
Result_t AllocateMatrix(Matrix_t *matrix, long n);
void FreeMatrix(Matrix_t *matrix);

void OddSquare(Matrix_t *matrix);
void EvenEvenSquare(Matrix_t *matrix);
void EvenOddSquare(Matrix_t *matrix);

void MakeMagicSquare(int *);

#ifdef __cplusplus
}
#endif

#endif // LR4_TASK_6_APP_H_