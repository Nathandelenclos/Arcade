cmake_minimum_required(VERSION 3.24)
project(Arcade_libraries)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)
add_library(arcade_sfml SHARED)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
add_library(arcade_sdl2 SHARED)

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
        Graphical/SFML/LibSFML.cpp Graphical/SFML/LibSFML.hpp
        Graphical/SFML/Sprite.cpp  Graphical/SFML/Sprite.hpp
        Graphical/SFML/Text.cpp Graphical/SFML/Text.hpp
        Graphical/SFML/Object.hpp
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
        Graphical/SDL/LibSDL.cpp Graphical/SDL/LibSDL.hpp
        Graphical/SDL/SDL.hpp Graphical/SDL/Event.cpp
        Graphical/SDL/Texture.cpp
        Graphical/SDL/Surface.cpp
        Graphical/SDL/Renderer.cpp
        Graphical/SDL/Window.cpp
)

target_link_libraries(arcade_sdl2 SDL2 SDL2_ttf SDL2_image)

# libNCURSES

set_target_properties(
        arcade_ncurses
        PROPERTIES
        PREFIX ""
)

target_sources(
        arcade_ncurses
        PRIVATE
        Graphical/NCURSES/LibNCURSES.cpp Graphical/NCURSES/LibNCURSES.hpp
        Graphical/NCURSES/ncurses.cpp Graphical/NCURSES/ncurses.hpp
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
        Games/Snake/SnakeGame.cpp
        Games/Snake/SnakeGame.hpp
        Games/Snake/Entity.cpp
        Games/Snake/Entity.hpp
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
        Games/Pacman/Grid.cpp
        Games/Pacman/Grid.hpp
)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)