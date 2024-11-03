#include "ctoast/control.h"
#include "ctoast/io.h"
#include "lr/task_6.h"

int main(void) {
  PrintGreeting(6, "Вводит n и строит магический квадрат порядка n.");

  int should_close = 0;
  while (!should_close) {
    Loop(&should_close, &MakeMagicSquare);
  }

  return 0;
}
