/*
** EPITECH PROJECT, 2023
** B_OOP_400_LIL_4_1_arcade_nathan_delenclos
** File description:
** ncurses.cpp
*/

#include "ncurses.hpp"

namespace Arcade {
    namespace ncurses {
        /**
         * @brief Construct a new Window:: Window object
         */
        Window::Window() = default;

        /**
         * @brief Destroy the Window:: Window object
         */
        Window::~Window() = default;

        /**
         * @brief Get the Key object
         * @return int - The key
         */
        int Window::getKey()
        {
            return getch();
        }

        /**
         * @brief Open the window
         */
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

        /**
         * @brief Check if the window is open
         * @return true - The window is open
         * @return false - The window is closed
         */
        bool Window::isOpen()
        {
            return _window != nullptr;
        }

        /**
         * @brief Close the window
         */
        void Window::close()
        {
            endwin();
            _window = nullptr;
        }

        /**
         * @brief Clear the window
         */
        void Window::clearAll()
        {
            //wclear(_window);
        }

        /**
         * @brief Get the Event object
         * @return int - The event
         */
        int Window::poolEvent()
        {
            timeout(0);

            return getch();
        }

        /**
         * @brief Display the char
         * @param map charVectorPtr - The char to display
         */
        void Window::displayChar(const charVectorPtr &map)
        {
            werase(_window);
            for (const charPtr &i: *map) {
                attron(COLOR_PAIR(i->pair->getId()));
                mvwprintw(_window, i->y, i->x, "%c", i->chara);
                attroff(COLOR_PAIR(i->pair->getId()));
            }
            wrefresh(_window);
        }

        /**
         * @brief Display the text
         * @param map textVectorPtr - The text to display
         */
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

        /**
         * @brief Init Color
         * @param id int - The id of the color
         * @param save std::string - The save of the color
         * @param text color_t - The color
         */
        Color::Color(int id, const std::string &save, color_t color)
        {
            init_color(static_cast<short>(id), static_cast<short>(color.r * 2) , static_cast<short>(color.g * 2), static_cast<short>(color.b * 2));
            _save = save;
            _id = id;
        }

        /**
         * @brief Construct a new Color:: Color object
         * @param id int - The id of the color
         * @param text color_t - The color
         */
        Color::Color(int id, color_t text)
        {
            init_color(static_cast<short>(id), static_cast<short>(text.r * 2), static_cast<short>(text.g * 2), static_cast<short>(text.b * 2));
            _id = id;
            _save = std::to_string(text.r) + std::to_string(text.g) + std::to_string(text.b);
        }

        /**
         * @brief Get the Id object
         * @return int - The id
         */
        int Color::getId() const
        {
            return _id;
        }

        /**
         * @brief Get the Save object
         * @return std::string - The save
         */
        const std::string &Color::getSave() const
        {
            return _save;
        }

        /**
         * @brief Search the color by the color
         * @param v ColorVectorPtr - The vector of color
         * @param color color_t - The color
         * @return ColorPtr - The color
         */
        ColorPtr Color::searchByColor(const ColorVectorPtr& v, color_t color)
        {
            for (const ColorPtr& i: *v) {
                if (i->getSave() == std::to_string(color.r) + std::to_string(color.g) + std::to_string(color.b))
                    return i;
            }
            return nullptr;
        }

        /**
         * @brief Search the color by the color or create it
         * @param v ColorVectorPtr - The vector of color
         * @param color color_t - The color
         * @return ColorPtr - The color
         */
        ColorPtr Color::searchByColorOrCreate(const ColorVectorPtr &v, color_t color)
        {
            ColorPtr color_1 = searchByColor(v, color);
            if (color_1 == nullptr) {
                color_1 = std::make_shared<Color>(static_cast<int>(v->size() + 12), color);
                v->push_back(color_1);
            }
            return color_1;
        }

        /**
         * @brief Destroy the Color:: Color object
         */
        Color::~Color() = default;

        /**
         * @brief Construct a new Color Pair:: Color Pair object
         * @param color int - The color
         * @param background int - The background
         * @param id int - The id
         */
        ColorPair::ColorPair(int color, int background, int id)
        {
            _color = color;
            _background = background;
            _id = id;
            init_pair(static_cast<short>(id), static_cast<short>(color), static_cast<short>(background));
        }

        /**
         * @brief search the color pair by the color and the background
         * @param v ColorPairVectorPtr - The vector of color pair
         * @param color int - The color
         * @param background int - The background
         * @return ColorPairPtr - The color pair
         */
        ColorPairPtr ColorPair::searchByColorPair(const ColorPairVectorPtr &v, int color,
            int background)
        {
            for (const ColorPairPtr& i: *v) {
                if (i->_color == color && i->_background == background)
                    return i;
            }
            return nullptr;
        }

        /**
         * @brief search the color pair by the color and the background or create it
         * @param v ColorPairVectorPtr - The vector of color pair
         * @param color int - The color
         * @param background int - The background
         * @return ColorPairPtr - The color pair
         */
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

        /**
         * @brief Get the Color object
         * @return int - The color
         */
        int ColorPair::getColor() const
        {
            return _color;
        }

        /**
         * @brief Get the Background object
         * @return int - The background
         */
        int ColorPair::getBackground() const
        {
            return _background;
        }

        /**
         * @brief Get the Id object
         * @return int - The id
         */
        int ColorPair::getId() const
        {
            return _id;
        }
    }
}