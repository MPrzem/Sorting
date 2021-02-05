cmake_minimum_required(VERSION 3.10)
project(IntroSort)

add_executable(${PROJECT_NAME} main.cpp IntrospectiveSort.cpp)
add_executable(${PROJECT_NAME}-ut IntrospectiveSort-ut.cpp)