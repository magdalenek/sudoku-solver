cmake_minimum_required(VERSION 2.8.4)
project(sudoku)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        sudoku.cpp
        sudoku.h)

add_executable(sudoku ${SOURCE_FILES})