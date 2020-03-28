cmake_minimum_required(VERSION 3.14)
project(statlibcpp)

set(CMAKE_CXX_STANDARD 14)

include(cmake/include_googletest.cmake)

add_subdirectory(source)