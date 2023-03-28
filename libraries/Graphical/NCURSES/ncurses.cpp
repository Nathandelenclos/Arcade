/*
** EPITECH PROJECT, 2023
** B_OOP_400_LIL_4_1_arcade_nathan_delenclos
** File description:
** ncurses.cpp
*/

#include "ncurses.hpp"

namespace Arcade {
    namespace ncurses {
        Window::Window() = default;

        Window::~Window() = default;

        int Window::getKey()
        {
            return getch();
        }

        void Window::open()
        {
            _window = initscr();
            start_color();
            cbreak();
            noecho();
            keypad(_window, true);
            nodelay(_window, true);
            curs_set(0);
        }

        bool Window::isOpen()
        {
            return _window != nullptr;
        }

        void Window::close()
        {
            endwin();
            _window = nullptr;
        }

        void Window::clearAll()
        {
            clear();
        }

        int Window::poolEvent()
        {
            timeout(0);
            int event;

            while ((event = getch()) != 0 && event != ERR);
            return event;
        }

        void Window::displayChar(const std::shared_ptr<std::vector<std::shared_ptr<char_t>>> &map)
        {
            for (const std::shared_ptr<char_t>& i: *map) {
                init_color(1, i->color.r, i->color.g, i->color.b);
                init_pair(1, 1, 1);
                attron(COLOR_PAIR(1));
                mvprintw(i->x, i->y, "%c", i->chara);
                attroff(COLOR_PAIR(1));
            }
        }

        void Window::displayText(
            const textVectorPtr &map)
        {
            for (auto &i: *map) {
                init_color(1, i->color.r, i->color.g, i->color.b);
                init_pair(1, 1, COLOR_BLACK);
                attron(COLOR_PAIR(1));
                mvprintw(i->x, i->y, "%s", i->text.c_str());
                attroff(COLOR_PAIR(1));
            }
        }
    }
}