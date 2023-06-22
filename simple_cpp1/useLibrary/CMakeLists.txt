cmake_minimum_required(VERSION 3.15)

project(RUN)

find_library(LIB helloSLAM)

add_executable(run useLibrary.cpp)

target_link_libraries(run ${LIB})