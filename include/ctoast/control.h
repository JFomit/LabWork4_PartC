#ifndef CTOAST_CONTROL_H_
#define CTOAST_CONTROL_H_

typedef void (*RunnerFunction)(int *should_close);
void Loop(int *should_close, RunnerFunction runner);

#endif // LR4_CONTROL_H_