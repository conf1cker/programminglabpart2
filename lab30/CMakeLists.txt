cmake_minimum_required(VERSION 3.19)
project(lab30)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(lab30
        src/main.cpp
        src/task.cpp
        src/task.h)
