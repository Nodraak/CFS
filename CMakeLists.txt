cmake_minimum_required(VERSION 3.0)
project(Demo)

add_subdirectory(src/)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
