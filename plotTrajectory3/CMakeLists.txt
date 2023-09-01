cmake_minimum_required(VERSION 3.15)
project(DisplayTrajectory)

add_executable(run plot.cpp)

find_package(Pangolin REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})

target_link_libraries(run ${Pangolin_LIBRARIES})

