cmake_minimum_required(VERSION 3.15)

project(RUN)

add_library(xxx SHARED libHelloSLAM.cpp)

add_executable(run useLibrary.cpp)

target_link_libraries(run xxx)
