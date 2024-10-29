#include "ctoast/input.h"
#include <stdio.h>
#include <stdlib.h>

Result_t ReadLong(long *var) {
  char buffer[128] = "";
  long i;

  if (fgets(buffer, sizeof(buffer), stdin)) {
    char *end;
    i = strtol(buffer, &end, 10);
    if (end == buffer) {
      return kErr;
    } else {
      *var = i;
      return kOk;
    }
  }

  return kErr;
}

Result_t ReadDouble(double *var) {
  char buffer[128] = "";
  double i;

  if (fgets(buffer, sizeof(buffer), stdin)) {
    char *end;
    i = strtod(buffer, &end);
    if (end == buffer) {
      return kErr;
    } else {
      *var = i;
      return kOk;
    }
  }

  return kErr;
}