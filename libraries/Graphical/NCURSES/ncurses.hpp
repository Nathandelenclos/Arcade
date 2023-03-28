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

        typedef std::shared_ptr<char_t> charPtr;
        typedef std::vector<charPtr> charVector;
        typedef std::shared_ptr<charVector> charVectorPtr;

        typedef struct {
            color_t color;
            std::string text;
            int x;
            int y;
        } text_t;

        typedef std::shared_ptr<text_t> textPtr;
        typedef std::vector<textPtr> textVector;
        typedef std::shared_ptr<textVector> textVectorPtr;

        class Window {
            public:
                Window();
                ~Window();
                int getKey();
                void displayChar(const charVectorPtr& map);
                void displayText(const textVectorPtr& map);
                void open();
                void close();
                bool isOpen();
                void clearAll();
                int poolEvent();
            protected:
                WINDOW *_window{};

            private:
        };

        typedef std::shared_ptr<Window> WindowPtr;
        typedef std::vector<WindowPtr> WindowVector;
        typedef std::shared_ptr<WindowVector> WindowVectorPtr;
    }
}