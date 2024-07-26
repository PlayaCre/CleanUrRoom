cmake_minimum_required(VERSION 3.27)
project(CleanUrRoom)

set(CMAKE_CXX_STANDARD 17)

add_executable(CleanUrRoom main.cpp
        Source/FileHandler.cpp
        Header/FileHandler.h
)
