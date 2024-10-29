cmake_minimum_required(VERSION 3.20)

set(LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)

add_executable(tests task_5.c)

target_link_libraries(tests gtest_main)
add_test(NAME tests COMMAND tests_tests)