cmake_minimum_required(VERSION 3.15)
project(HelloSLAM)

add_executable(useHello useLibHello.cpp)

add_library(hello libHelloSLAM.cpp)

target_link_libraries(useHello hello)