cmake_minimum_required(VERSION 3.15)

project(UseLibrary)

set(CMAKE_CXX_STANDARD 17)

add_executable(run useLibrary.cpp)

find_library(LIB helloSLAM)

target_link_libraries(run ${LIB})