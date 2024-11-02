#include "ctoast/io.h"
#include "ctoast/result.h"
#include "lr/task_5.h"
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Result_t AllocateField(const size_t m, const size_t n, Field_t *field) {
  char **matrix = (char **)malloc(m * n * sizeof(char));
  memset(matrix, (int)'0', n * m * sizeof(char));

  if (!matrix) {
    field->matrix = NULL;
    field->m = 0;
    field->n = 0;
    return kErr;
  }

  *field = (Field_t){.matrix = matrix, .m = (long)m, .n = (long)n};
  return kOk;
}

char *CellAt(Field_t *field, const long i, const long j) {
  if (i < 0 || i >= field->m || j < 0 || j >= field->n) {
    return NULL;
  }

  return (char *)field->matrix + field->m * i + j;
}

void FreeField(Field_t *field) {
  free(field->matrix);

  field->matrix = NULL;
  field->m = 0;
  field->n = 0;
}

void ProcessDot(Field_t *field, const long i, const long j) {
  char c = *CellAt(field, i, j);
  if (c == 0) {
    c = '0';
  }
}

void ProcessStar(Field_t *field, const long i, const long j) {
  *CellAt(field, i, j) = '*';

  for (long ni = (long)i - 1; ni <= (long)i + 1; ++ni) {
    for (long nj = (long)j - 1; nj <= (long)j + 1; ++nj) {

      char *address = CellAt(field, ni, nj);

      if (address && isdigit(*address)) {
        *address += 1;
      }
    }
  }
}

Result_t ReadProcessReportErr(Field_t *field) {
  for (long i = 0; i < field->m; ++i) {
    for (long j = 0; j < field->n; ++j) {
      char c;
      if (!ReadChar(&c)) {
        printf("Ожидался символ `.' или `*'.\n");
        return kErr;
      }

      switch (c) {
      case '.':
        ProcessDot(field, i, j);
        break;
      case '*':
        ProcessStar(field, i, j);
        break;
      default:
        printf("Ожидался символ `.' или `*'.\n");
        return kErr;
      }
    }
    char c;
    if (!ReadChar(&c) || c != '\n') {
      (void)fprintf(stderr, "Ожидался символ `\\n'.\n");
      return kErr;
    }
  }

  return kOk;
}
