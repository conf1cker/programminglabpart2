cmake_minimum_required(VERSION 3.19)
project(lab28)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(lab28
        src/main.cpp
        src/menu.cpp
        src/menu.h
        src/tasks.cpp
        src/tasks.h)
