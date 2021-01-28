cmake_minimum_required(VERSION 3.10)
project(MergeSort)

add_executable(MergeSort main.cpp MergeSort.cpp)
target_link_libraries(MergeSort m)
