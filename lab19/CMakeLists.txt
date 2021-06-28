cmake_minimum_required(VERSION 3.19)
project(lab19 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)


add_executable(lab19_main        src/guitar.c        src/guitar.h        src/list.c        src/list.h        src/main.c        )
add_executable(lab19_test test/test.c src/list.c src/guitar.c)
