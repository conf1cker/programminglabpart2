cmake_minimum_required(VERSION 3.19)
project(lab27)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(lab27
        src/guitar.cpp
        src/guitar.h
        src/list.cpp
        src/list.h
        src/main.cpp)
