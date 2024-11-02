#include "ctoast/io.h"
#include "ctoast/result.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

Result_t ReadLine(char *buffer, int size) {
  return fgets(buffer, size, stdin) ? kOk : kErr;
}

Result_t ReadChar(char *var) {
  int c = getchar();
  if (c != EOF) {
    *var = (char)c;
    return kOk;
  }

  return kErr;
}

Result_t ReadCharFromLine(char *var) {
  char buffer[128] = "";

  Result_t result = ReadLine(buffer, sizeof(buffer));

  if (result != kOk) {
    return result;
  }
  if (sscanf(buffer, "%1c", var) == 1) {
    return kOk;
  }

  return kErr;
}

Result_t ReadLong(long *var) {
  char buffer[128] = "";

  Result_t result = ReadLine(buffer, sizeof(buffer));
  if (result != kOk) {
    return result;
  }

  char *end;
  errno = 0;
  *var = strtol(buffer, &end, 10);
  return end == buffer || errno ? kErr : kOk;
}

Result_t ReadDouble(double *var) {
  char buffer[128] = "";

  Result_t result = ReadLine(buffer, sizeof(buffer));
  if (result != kOk) {
    return result;
  }

  char *end;
  *var = strtod(buffer, &end);
  errno = 0;
  return end == buffer || errno ? kErr : kOk;
}

void PrintGreeting(const int task_number, const char *description) {
  printf("Задание %i\n", task_number);
  printf("Выполнил Забережный Тимофей, гр. 453501\n");
  printf("%s\n", description);
  printf("---------------------------\n");
}