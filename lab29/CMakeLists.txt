cmake_minimum_required(VERSION 3.19)
project(lab29)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(lab29
        src/list.hpp
        src/main.cpp)
