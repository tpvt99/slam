cmake_minimum_required(VERSION 3.15)

# Project name
project(HelloSLAM)

# Add library
add_library(helloSLAM libHelloSLAM.cpp)

# Install library
install(TARGETS helloSLAM DESTINATION lib)
install(FILES libHelloSLAM.h DESTINATION include)