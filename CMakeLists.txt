cmake_minimum_required(VERSION 3.24)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
project(Arcade)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(arcade
        src/main.cpp)

add_subdirectory(libraries)
