cmake_minimum_required(VERSION 3.15)
project(DisplayTrajectory)

add_executable(run plot.cpp)

include_directories("../3rdparty/eigen")
include_directories("../3rdparty/Pangolin")



include(FetchContent)

FetchContent_Declare(
  libglew
  GIT_REPOSITORY https://github.com/nigels-com/glew.git
  GIT_TAG        gloew-2.2.0
)

FetchContent_MakeAvailable(libglew)
