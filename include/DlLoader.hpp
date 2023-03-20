/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** DlLoader.hpp
*/

#pragma once

#include <iostream>
#include <exception>
#include <dlfcn.h>
#include <memory>
#include <utility>

namespace Arcade {
    template<typename Loader>
    class DlLoader {
        public:
            class LibError : public std::exception {
                public:
                    explicit LibError(std::string msg) : _msg(std::move(msg))
                    {};

                    const char *what() const noexcept override
                    {
                        return (_msg.c_str());
                    }

                protected:
                    const std::string _msg;
            };

            explicit DlLoader(const std::string &path) : _handle(
                    dlopen(path.c_str(), RTLD_LAZY))
            {
                if (!_handle)
                    throw LibError("Cannot open " + path + ": ");
            }

            ~DlLoader()
            {
                if (_handle) {
                    std::cout << "Closing library" << std::endl;
                    dlclose(_handle);
                }
            }

            std::shared_ptr<Loader> getGraphInstance()
            {
                std::shared_ptr<Arcade::IGraphicLib> lib;
                auto entryPoint = dlsym(_handle, GRAPHICSYM);

                if (!entryPoint)
                    throw LibError("Cannot load symbol 'constructor_graphic': ");
                auto *(*libfoo)() = (Arcade::IGraphicLib *(*)()) entryPoint;
                lib = std::shared_ptr<Arcade::IGraphicLib>(libfoo());

                if (!lib)
                    throw LibError("Cannot load symbol 'constructor_graphic': ");
                return (lib);
            }

            std::shared_ptr<Loader> getGameInstance()
            {
                std::shared_ptr<Arcade::IGameLib> lib;
                auto entryPoint = dlsym(_handle, GAMESYM);

                if (!entryPoint)
                    throw LibError("Cannot load symbol 'constructor_game': ");
                auto *(*libfoo)() = (Arcade::IGameLib *(*)()) entryPoint;
                lib = std::shared_ptr<Arcade::IGameLib>(libfoo());

                if (!lib)
                    throw LibError("Cannot load symbol 'constructor_game': ");
                return (lib);
            }

        protected:
            void *_handle;
    };
    typedef Arcade::DlLoader<Arcade::IGraphicLib> DlLoaderGraphic;
    typedef Arcade::DlLoader<Arcade::IGameLib> DlLoaderGame;
    typedef std::shared_ptr<Arcade::DlLoaderGraphic> DlLoaderGraphicPtr;
    typedef std::shared_ptr<Arcade::DlLoaderGame> DlLoaderGamePtr;
}
