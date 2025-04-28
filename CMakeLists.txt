cmake_minimum_required(VERSION 3.22)
project(ChengZiList)
add_subdirectory(lib/googletest)
set(CMAKE_CXX_STANDARD 17)
include_directories(src)


add_subdirectory(src)
add_subdirectory(test)