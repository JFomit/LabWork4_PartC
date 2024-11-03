#include "lr/task_5.h"
#include <cmath>
#include "gtest/gtest.h"

TEST(task_5_tests, simple) {
  // Arrange
  Field_t field;
  EXPECT_TRUE(AllocateField(3, 3, &field));
  for (size_t i = 0; i < 3; ++i) {
    for (size_t j = 0; j < 3; ++j) {}
  }
  // Act
  // Assert

  // Cleanup
  FreeField(&field);
}