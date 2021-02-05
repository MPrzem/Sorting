cmake_minimum_required(VERSION 3.10)
project(QuickSort)

add_executable(QuickSort QuickSort.cpp)
add_executable(${PROJECT_NAME}-ut QuickSort-ut.cpp)