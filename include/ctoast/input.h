#ifndef CTOAST_INPUT_H_
#define CTOAST_INPUT_H_

typedef enum Result { kErr = 0, kOk = 1 } Result_t;

Result_t ReadLong(long *var);
Result_t ReadDouble(double *var);

#endif // LR4_INPUT_H_