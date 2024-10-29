cmake_minimum_required(VERSION 3.20)

project(LR4PartC)
set(LANGUAGES C)
set(CMAKE_C_STANDARD 99)
set(C_STANDARD_REQUIRED ON)

enable_testing()

include_directories(include)

add_subdirectory(lib/ctoast)
add_subdirectory(Task_5)
add_subdirectory(tests)
add_subdirectory(lib/googletest)
