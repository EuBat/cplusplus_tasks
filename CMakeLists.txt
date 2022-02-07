cmake_minimum_required(VERSION 3.5)

project(task7 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_SYSTEM_NAME IOS)
add_executable(task7
                matrix.cpp
                     matrix.h
                     matrix_exception.h
                     loader.h
                     sorter.h)
