cmake_minimum_required(VERSION 3.19)
project(RGZ)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(RGZ
        src/list.cpp
        src/list.h
        src/guitar.cpp
        src/guitar.h
        src/menu.cpp
        src/menu.h
        src/controller.cpp
        src/controller.h
        src/main.cpp)
