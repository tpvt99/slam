cmake_minimum_required(VERSION 3.15)

project(EigenMatrix)

include_directories("../3rdparty/eigen")

add_executable(eigen eigenMatrix.cpp)

