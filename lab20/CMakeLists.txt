cmake_minimum_required(VERSION 3.19)
project(lab20 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable (lab20
        src/guitar.c
        src/guitar.h
        src/list.c
        src/list.h
        src/main.c)
add_executable (lab20_test test/test.c src/list.c    src/guitar.c)
