cmake_minimum_required(VERSION 3.24)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
project(Arcade)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

add_executable(arcade
        src/main.cpp
        src/Core/Core.cpp include/Core.hpp
        src/Utils.cpp src/Utils.cpp src/Core/Text.hpp src/Core/Text.cpp)

add_subdirectory(libraries)
