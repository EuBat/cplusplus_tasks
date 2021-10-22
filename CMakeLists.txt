cmake_minimum_required(VERSION 3.5)

project(task5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task5 main.cpp matrix.h matrix.cpp)
