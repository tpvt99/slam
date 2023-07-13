cmake_minimum_required(VERSION 3.15)

project(UsingSophus)

add_executable(run useSophus.cpp)

include(FetchContent)

FetchContent_Declare(
  fmtlib
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG        8.0.1
)

FetchContent_MakeAvailable(fmtlib)

#find_package(Sophus REQUIRED)
#include_directories(${Sophus_INCLUDE_DIRS})
include_directories("../3rdparty/Sophus")
include_directories("../3rdparty/eigen")

target_link_libraries(run fmt::fmt)
