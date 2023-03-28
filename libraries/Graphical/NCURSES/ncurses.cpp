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

        void Window::displayChar(const charVectorPtr &map)
        {
            for (const charPtr &i: *map) {
                attron(COLOR_PAIR(1));
                mvprintw(i->x, i->y, "%c", i->chara);
                attroff(COLOR_PAIR(1));
            }
        }

        void Window::displayText(
            const textVectorPtr &map)
        {
            for (auto &i: *map) {
                init_pair(1, static_cast<short>(i->color), static_cast<short>(i->colorBackground));
                attron(COLOR_PAIR(1));
                mvprintw(i->x, i->y, "%s", i->text.c_str());
                attroff(COLOR_PAIR(1));
            }
        }

        Color::Color(int id, const std::string &save, color_t color)
        {
            init_color(static_cast<short>(id), static_cast<short>(color.r * 2) , static_cast<short>(color.g * 2), static_cast<short>(color.b * 2));
            _save = save;
            _id = id;
        }

        Color::Color(int id, color_t text)
        {
            init_color(static_cast<short>(id), static_cast<short>(text.r * 2), static_cast<short>(text.g * 2), static_cast<short>(text.b * 2));
            _id = id;
            _save = std::to_string(text.r) + std::to_string(text.g) + std::to_string(text.b);
        }

        int Color::getId() const
        {
            return _id;
        }

        const std::string &Color::getSave() const
        {
            return _save;
        }

        ColorPtr Color::searchByColor(const ColorVectorPtr& v, color_t color)
        {
            for (const ColorPtr& i: *v) {
                if (i->getSave() == std::to_string(color.r) + std::to_string(color.g) + std::to_string(color.b))
                    return i;
            }
            return nullptr;
        }

        ColorPtr Color::searchByColorOrCreate(const ColorVectorPtr &v, color_t color)
        {
            ColorPtr color_1 = searchByColor(v, color);
            if (color_1 == nullptr) {
                color_1 = std::make_shared<Color>(static_cast<int>(v->size() + 12), color);
                v->push_back(color_1);
            }
            return color_1;
        }

        Color::~Color() = default;

        ColorPair::ColorPair(int color, int background, int id)
        {
            _color = color;
            _background = background;
            _id = id;
            init_pair(static_cast<short>(id), static_cast<short>(color), static_cast<short>(background));
        }

        ColorPairPtr ColorPair::searchByColorPair(const ColorPairVectorPtr &v, int color,
            int background)
        {
            for (const ColorPairPtr& i: *v) {
                if (i->_color == color && i->_background == background)
                    return i;
            }
            return nullptr;
        }

        ColorPairPtr ColorPair::searchByColorPairOrCreate(const ColorPairVectorPtr &v,
            int color, int background)
        {
            ColorPairPtr colorPair = searchByColorPair(v, color, background);
            if (colorPair == nullptr) {
                colorPair = std::make_shared<ColorPair>(color, background, static_cast<int>(v->size() + 1));
                v->push_back(colorPair);
            }
            return colorPair;
        }

        int ColorPair::getColor() const
        {
            return _color;
        }

        int ColorPair::getBackground() const
        {
            return _background;
        }

        int ColorPair::getId() const
        {
            return _id;
        }

    }
}