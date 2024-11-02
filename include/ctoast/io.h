#ifndef CTOAST_INPUT_H_
#define CTOAST_INPUT_H_

#include "ctoast/result.h"

Result_t ReadLine(char *buffer, int size);
Result_t ReadLong(long *var);
Result_t ReadDouble(double *var);
Result_t ReadChar(char *var);
Result_t ReadCharFromLine(char *var);

void PrintGreeting(const int task_number, const char *description);

#endif // LR4_INPUT_H_