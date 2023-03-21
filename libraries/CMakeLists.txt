cmake_minimum_required(VERSION 3.24)
project(Arcade_libraries)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)
add_library(arcade_sfml SHARED Graphical/SFML/Sprite.hpp Graphical/SFML/Sprite.cpp Graphical/SFML/Text.hpp Graphical/SFML/Text.cpp Graphical/SFML/Object.hpp)

find_package(SDL2 REQUIRED)
add_library(arcade_sdl2 SHARED Graphical/SDL/SDL.hpp Graphical/SDL/SDL.cpp)

add_library(arcade_ncurses SHARED)

add_library(arcade_snake SHARED)

add_library(arcade_pacman SHARED)

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

target_link_libraries(arcade_sfml sfml-graphics sfml-window sfml-system)


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

target_link_libraries(arcade_sdl2 SDL2)

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

target_link_libraries(arcade_ncurses ncurses)

# libSnake

set_target_properties(
        arcade_snake
        PROPERTIES
        PREFIX ""
)

target_sources(
        arcade_snake
        PRIVATE
        Games/Snake/Snake.cpp
        Games/Snake/Snake.hpp
)

# libPacman

set_target_properties(
        arcade_pacman
        PROPERTIES
        PREFIX ""
)

target_sources(
        arcade_pacman
        PRIVATE
        Games/Pacman/Pacman.cpp
        Games/Pacman/Pacman.hpp
)
