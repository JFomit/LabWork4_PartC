#include "lr/task_5.h"
#include <cmath>
#include "gtest/gtest.h"

TEST(task_5, simple) {
  // Arrange
  Field_t field;
  EXPECT_TRUE(AllocateField(3, 3, &field));
  // Act
  for (long i = 0; i < field.m; ++i) {
    for (long j = 0; j < field.n; ++j) {
      ProcessChar(&field, i == j ? '*' : '.', i, j);
    }
  }
  char *stringified = (char *)field.matrix;
  // Assert
  ASSERT_STREQ(stringified, "*212*212*");
  // Cleanup
  FreeField(&field);
}

TEST(task_5, all_empty) {
  // Arrange
  Field_t field;
  EXPECT_TRUE(AllocateField(5, 5, &field));
  // Act
  for (long i = 0; i < field.m; ++i) {
    for (long j = 0; j < field.n; ++j) {
      ProcessChar(&field, '.', i, j);
    }
  }
  char *stringified = (char *)field.matrix;
  // Assert
  ASSERT_STREQ(stringified, "0000000000000000000000000");
  // Cleanup
  FreeField(&field);
}

TEST(task_5, all_mines) {
  // Arrange
  Field_t field;
  EXPECT_TRUE(AllocateField(4, 4, &field));
  // Act
  for (long i = 0; i < field.m; ++i) {
    for (long j = 0; j < field.n; ++j) {
      ProcessChar(&field, '*', i, j);
    }
  }
  char *stringified = (char *)field.matrix;
  // Assert
  ASSERT_STREQ(stringified, "****************");
  // Cleanup
  FreeField(&field);
}

TEST(task_5, one_row) {
  // Arrange
  Field_t field;
  EXPECT_TRUE(AllocateField(4, 1, &field));
  // Act
  for (long i = 0; i < field.m; ++i) {
    for (long j = 0; j < field.n; ++j) {
      ProcessChar(&field, '.', i, j);
    }
  }
  ProcessChar(&field, '*', 0, 0);
  ProcessChar(&field, '*', 2, 0);
  char *stringified = (char *)field.matrix;
  // Assert
  ASSERT_STREQ(stringified, "*2*1");
  // Cleanup
  FreeField(&field);
}