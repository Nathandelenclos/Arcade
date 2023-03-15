cmake_minimum_required(VERSION 3.24)
project(Arcade_Libraries)

set(CMAKE_CXX_STANDARD 14)

add_library(LibSFML SHARED)

add_library(LibSDL SHARED)

add_library(LibNCURSES SHARED)

# libSFML

set_target_properties(
        LibSFML
        PROPERTIES
        PREFIX ""
)

target_sources(
        LibSFML
        PRIVATE
        Graphical/SFML/LibSFML.cpp
        Graphical/SFML/LibSFML.hpp
)

# libSDL

set_target_properties(
        LibSDL
        PROPERTIES
        PREFIX ""
)

target_sources(
        LibSDL
        PRIVATE
        Graphical/SDL/LibSDL.cpp
        Graphical/SDL/LibSDL.hpp
)

# libNCURSES

set_target_properties(
        LibNCURSES
        PROPERTIES
        PREFIX ""
)

target_sources(
        LibNCURSES
        PRIVATE
        Graphical/NCURSES/LibNCURSES.cpp
        Graphical/NCURSES/LibNCURSES.hpp
)
