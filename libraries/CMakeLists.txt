cmake_minimum_required(VERSION 3.24)
project(Arcade_libraries)

set(CMAKE_CXX_STANDARD 14)

add_library(arcade_sfml SHARED)

add_library(arcade_sdl2 SHARED)

add_library(arcade_ncurses SHARED)

# libSFML

set_target_properties(
        arcade_sfml
        PROPERTIES
        PREFIX ""
)

target_sources(
        arcade_sfml
        PRIVATE
        Graphical/SFML/LibSFML.cpp
        Graphical/SFML/LibSFML.hpp
)

# libSDL

set_target_properties(
        arcade_sdl2
        PROPERTIES
        PREFIX ""
)

target_sources(
        arcade_sdl2
        PRIVATE
        Graphical/SDL/LibSDL.cpp
        Graphical/SDL/LibSDL.hpp
)

# libNCURSES

set_target_properties(
        arcade_ncurses
        PROPERTIES
        PREFIX ""
)

target_sources(
        arcade_ncurses
        PRIVATE
        Graphical/NCURSES/LibNCURSES.cpp
        Graphical/NCURSES/LibNCURSES.hpp
)
