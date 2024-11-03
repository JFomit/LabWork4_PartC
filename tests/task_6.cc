#include "lr/task_6.h"
#include "gtest/gtest.h"

bool TestMagicSquare(Matrix_t *matrix) {
  long n = matrix->n;
  bool correct = true;
  long magic_sum = n * (n * n + 1) / 2;

  long sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += *At(matrix, i, i);
  }
  correct = correct && (sum == magic_sum);
  sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += *At(matrix, i, n - 1 - i);
  }
  correct = correct && (magic_sum == sum);

  for (int i = 0; i < n; ++i) {
    long row = 0;
    for (int j = 0; j < n; ++j) {
      row += *At(matrix, j, i);
    }
    correct = correct && row == magic_sum;
  }
  for (int i = 0; i < n; ++i) {
    long col = 0;
    for (int j = 0; j < n; ++j) {
      col += *At(matrix, i, j);
    }
    correct = correct && col == magic_sum;
  }

  return correct;
}

TEST(task_6, odd) {
  // Arrange
  Matrix_t matrix;
  EXPECT_TRUE(AllocateMatrix(&matrix, 289));
  // Act
  OddSquare(&matrix);
  // Assert
  ASSERT_PRED1(TestMagicSquare, &matrix);
  // Cleanup
  FreeMatrix(&matrix);
}

TEST(task_6, even_even) {
  // Arrange
  Matrix_t matrix;
  EXPECT_TRUE(AllocateMatrix(&matrix, 8192));
  // Act
  EvenEvenSquare(&matrix);
  // Assert
  ASSERT_PRED1(TestMagicSquare, &matrix);
  // Cleanup
  FreeMatrix(&matrix);
}

TEST(task_6, even_odd) {
  // Arrange
  Matrix_t matrix;
  EXPECT_TRUE(AllocateMatrix(&matrix, 10));
  // Act
  EvenOddSquare(&matrix);
  // Assert
  ASSERT_PRED1(TestMagicSquare, &matrix);
  // Cleanup
  FreeMatrix(&matrix);
}
