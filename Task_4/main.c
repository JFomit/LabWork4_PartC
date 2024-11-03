#include "ctoast/control.h"
#include "ctoast/io.h"
#include "lr/task_4.h"

int main() {
  PrintGreeting(
      4, "Вводит трехмерный динамический массив из n^3 целых неотрицательных "
         "чисел и определяет диагональ с наибольшей суммой элементов.");
  int should_close = 0;
  while (!should_close) {
    Loop(&should_close, &Run);
  }

  return 0;
}