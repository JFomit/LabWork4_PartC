#include "lr/task_4.h"
#include <cstddef>
#include "gtest/gtest.h"

TEST(task_4, equal_diagonals) {
  // Arrange
  const size_t n = 3;
  long array[n * n * n];
  for (size_t i = 0; i < n * n * n; ++i) {
    array[i] = (long)i + 1;
  }
  // Act
  size_t diag = GetMaxSumDiagonalNo(array, n);
  // Assert
  ASSERT_EQ(diag, 0);  // should return firts of them - all equal to 42.
}

TEST(task_4, single) {
  // Arrange
  const size_t n = 1;
  long array[n * n * n];
  for (size_t i = 0; i < n * n * n; ++i) {
    array[i] = (long)i + 1;
  }
  // Act
  size_t diag = GetMaxSumDiagonalNo(array, n);
  // Assert
  ASSERT_EQ(diag, 0);
}

TEST(task_4, all_zeros) {
  // Arrange
  const size_t n = 16;
  long array[n * n * n];
  for (long &i : array) {
    i = 0;
  }
  // Act
  size_t diag = GetMaxSumDiagonalNo(array, n);
  // Assert
  ASSERT_EQ(diag, 0);  // should return firts of them - all equal to 42.
}

TEST(task_4, second_diagonal) {
  // Arrange
  const size_t n = 3;
  long array[n * n * n] = {};
  array[8] = 1;
  array[13] = 1;
  array[18] = 1;
  // Act
  size_t diag = GetMaxSumDiagonalNo(array, n);
  // Assert
  ASSERT_EQ(diag, 1);
}