cmake_minimum_required(VERSION 3.10)
project(MergeSort)

add_executable(MergeSort main.cpp MergeSort.cpp)
add_executable(${PROJECT_NAME}-ut MergeSort-ut.cpp)
target_link_libraries(MergeSort m)
