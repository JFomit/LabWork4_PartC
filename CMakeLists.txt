cmake_minimum_required(VERSION 3.20)

project(LR4PartC)
enable_testing()

include_directories(include)

add_subdirectory(lib/ctoast)
add_subdirectory(Task_5)
add_subdirectory(Task_4)
add_subdirectory(tests)
add_subdirectory(lib/googletest)
