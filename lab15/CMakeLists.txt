cmake_minimum_required(VERSION 3.17)
project(lab15 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab15_main src/main.c src/lib.c src/lib.h)
add_executable(lab15_test test/test.c  src/lib.c)