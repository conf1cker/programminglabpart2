cmake_minimum_required(VERSION 3.19)
project(lab24)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(lab24
        src/guitar.cpp
        src/guitar.h
        src/list.cpp
        src/list.h
        src/main.cpp)
add_executable(lab24_test test/test.cpp src/list.cpp src/guitar.cpp)