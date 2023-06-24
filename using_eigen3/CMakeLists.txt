cmake_minimum_required(VERSION 3.15)

project(EigenMatrix)

include_directories("/usr/include/eigen3")

add_executable(eigen eigenMatrix.cpp)

