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
            int color;
            int colorBackground;
            std::string text;
            int x;
            int y;
        } text_t;

        typedef std::shared_ptr<text_t> textPtr;
        typedef std::vector<textPtr> textVector;
        typedef std::shared_ptr<textVector> textVectorPtr;

        class Color;

        typedef std::shared_ptr<Color> ColorPtr;
        typedef std::vector<ColorPtr> ColorVector;
        typedef std::shared_ptr<ColorVector> ColorVectorPtr;

        class Color {
            public:
                Color(int save, const std::string &id, color_t text);
                Color(int save, color_t text);
                ~Color();
                static ColorPtr
                searchByColor(const ColorVectorPtr &v, color_t color);
                static ColorPtr
                searchByColorOrCreate(const ColorVectorPtr &v, color_t color);
                const std::string &getSave() const;
                int getId() const;
            protected:
                int _id;
                std::string _save;
            private:
        };

        class ColorPair;

        typedef std::shared_ptr<ColorPair> ColorPairPtr;
        typedef std::vector<ColorPairPtr> ColorPairVector;
        typedef std::shared_ptr<ColorPairVector> ColorPairVectorPtr;

        class ColorPair {
            public:
                ColorPair(int color, int background, int id);
                ~ColorPair() = default;
                static ColorPairPtr
                searchByColorPair(const ColorPairVectorPtr &v, int color,
                    int background);
                static ColorPairPtr
                searchByColorPairOrCreate(const ColorPairVectorPtr &v,
                    int color, int background);
                int getColor() const;
                int getBackground() const;
                int getId() const;
            private:
                int _color;
                int _background;
                int _id;
        };

        typedef struct {
            ColorPairPtr pair;
            char chara;
            int x;
            int y;
        } char_t;

        typedef std::shared_ptr<char_t> charPtr;
        typedef std::vector<charPtr> charVector;
        typedef std::shared_ptr<charVector> charVectorPtr;

        class Window {
            public:
                Window();
                ~Window();
                int getKey();
                void displayChar(const charVectorPtr &map);
                void displayText(const textVectorPtr &map);
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