cmake_minimum_required(VERSION 3.26)
project(sort)

set(CMAKE_CXX_STANDARD 17)

file (GLOB SRC "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.cpp")
include_directories(lib)
add_executable(sort main.cpp)
target_sources(sort PUBLIC ${SRC})
add_executable(test test.cpp)