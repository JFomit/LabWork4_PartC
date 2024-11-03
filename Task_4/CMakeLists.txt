cmake_minimum_required(VERSION 3.20)
set(TASK task_4)

add_library(${TASK}_lib STATIC app.c)
target_link_libraries(${TASK}_lib PUBLIC ctoast)

add_executable(${TASK} main.c)
target_link_libraries(${TASK} PUBLIC ctoast ${TASK}_lib)