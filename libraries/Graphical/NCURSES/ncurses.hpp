/*
** EPITECH PROJECT, 2023
** B_OOP_400_LIL_4_1_arcade_nathan_delenclos
** File description:
** ncurses.hpp
*/

#pragma once

#include "iostream"
#include "vector"
#include "memory"
#include "Types.hpp"
#include <ncurses.h>

namespace Arcade {
    namespace ncurses {

        typedef struct {
            color_t color;
            char chara;
            int x;
            int y;
        } char_t;

        class Window {
            public:
                Window();
                ~Window();
                int getKey();
                void displayChar(const std::shared_ptr<std::vector<char_t>>& map);
                void displayText(const std::shared_ptr<std::vector<std::string>>& map);
                void open();
                void close();
                bool isOpen();
                void clearAll();
                int poolEvent();
            protected:
                WINDOW *_window;

            private:
        };

        typedef std::shared_ptr<Window> WindowPtr;
        typedef std::vector<WindowPtr> WindowVector;
        typedef std::shared_ptr<WindowVector> WindowVectorPtr;
    }
}