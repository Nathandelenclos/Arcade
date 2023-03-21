/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** SDL.cpp
*/

#include "SDL.hpp"

namespace Arcade {
    namespace sdl {
        Window::Window()
        {
            SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
            if (win == nullptr) {
                std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
                exit(84);
            }
            SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (ren == nullptr) {
                SDL_DestroyWindow(win);
                std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
                exit(84);
            }
            SDL_Surface *bmp = SDL_LoadBMP("hello.bmp");
            if (bmp == nullptr) {
                SDL_DestroyRenderer(ren);
                SDL_DestroyWindow(win);
                std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
                exit(84);
            }
            SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
            SDL_FreeSurface(bmp);
            if (tex == nullptr) {
                SDL_DestroyRenderer(ren);
                SDL_DestroyWindow(win);
                std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
                exit(84);
            }
            for (int i = 0; i < 3; ++i) {
                SDL_RenderClear(ren);
                SDL_RenderCopy(ren, tex, NULL, NULL);
                SDL_RenderPresent(ren);
                SDL_Delay(1000);
            }
            SDL_DestroyTexture(tex);
            SDL_DestroyRenderer(ren);
            SDL_DestroyWindow(win);
            SDL_Quit();
        }

        Window::~Window() = default;
    }
}