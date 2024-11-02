#include "lr/task_5.h"
#include <cmath>
#include "gtest/gtest.h"

TEST(task_5_tests, simple) {
  // Arrange
  Field_t field;
  EXPECT_TRUE(AllocateField(3, 3, &field));
  // Act
  // Assert
  // Cleanup
  FreeField(&field);
}