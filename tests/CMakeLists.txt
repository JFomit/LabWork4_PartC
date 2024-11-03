cmake_minimum_required(VERSION 3.20)

add_executable(tests task_5.cc task_4.cc task_6.cc)

set_target_properties(tests PROPERTIES
  LANGUAGES CXX
  CMAKE_CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON)

target_link_libraries(tests PUBLIC gtest_main task_5_lib task_4_lib task_6_lib)
add_test(NAME tests COMMAND ctest)