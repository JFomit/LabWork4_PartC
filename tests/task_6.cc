#include "lr/task_6.h"
#include "gtest/gtest.h"

bool TestMagicSquare(Matrix_t *matrix) {
  long n = matrix->n;
  bool correct = true;

  long main_diagonal = 0;
  long secondary_diagonal = 0;
  for (int i = 0; i < n; ++i) {
    main_diagonal += *At(matrix, i, i);
  }
  for (int i = 0; i < n; ++i) {
    secondary_diagonal += *At(matrix, i, n - i);
  }
  correct = correct && (main_diagonal == secondary_diagonal);

  for (int i = 0; i < n; ++i) {
    long row = 0;
    for (int j = 0; j < n; ++j) {
      row += *At(matrix, j, i);
    }
    correct = correct && row == main_diagonal;
  }
  for (int i = 0; i < n; ++i) {
    long col = 0;
    for (int j = 0; j < n; ++j) {
      col += *At(matrix, i, j);
    }
    correct = correct && col == main_diagonal;
  }

  return correct;
}

TEST(task_6, odd) {
  // Arrange
  Matrix_t matrix;
  EXPECT_TRUE(AllocateMatrix(&matrix, 3));
  // Act
  OddSquare(&matrix);
  // Assert
  ASSERT_PRED1(TestMagicSquare, &matrix);
  // Cleanup
  FreeMatrix(&matrix);
}