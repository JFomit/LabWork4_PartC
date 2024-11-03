#ifndef LR4_TASK_5_H_
#define LR4_TASK_5_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ctoast/result.h"
#include <stddef.h>
typedef struct Field {
  char *matrix;
  long m;
  long n;
} Field_t;

Result_t AllocateField(const size_t m, const size_t n, Field_t *field);

char *CellAt(Field_t *field, const long i, const long j);

void FreeField(Field_t *field);

void ProcessChar(Field_t *field, char c, long i, long j);
Result_t ReadProcessReportErr(Field_t *field);

#ifdef __cplusplus
}
#endif

#endif // LR4_TASK_5_APP_H_