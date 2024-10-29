cmake_minimum_required(VERSION 3.20)
set(TASK task_5)

add_executable(${TASK} main.c app.c)
target_link_libraries(${TASK} PUBLIC ctoast)