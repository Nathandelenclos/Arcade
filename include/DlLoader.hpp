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
#include "IGraphicLib.hpp"
#include "IGameLib.hpp"

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
                dlerror();
            }

            std::shared_ptr<Loader> getGameInstance()
            {
                std::shared_ptr<Arcade::IGameLib> lib;
                auto entryPoint = dlsym(_handle, GAMESYM);

                if (!entryPoint)
                    throw LibError("Cannot load symbol 1 'constructor_game': ");
                auto *(*libfoo)() = (Arcade::IGameLib *(*)()) entryPoint;
                lib = std::shared_ptr<Arcade::IGameLib>(libfoo());

                if (!lib)
                    throw LibError("Cannot load symbol 2 'constructor_game': ");
                return (lib);
            }

        protected:
            void *_handle;
    };
    typedef DlLoader<IGraphicLib> DlLoaderGraphic;
    typedef DlLoader<IGameLib> DlLoaderGame;
    typedef std::shared_ptr<DlLoaderGraphic> DlLoaderGraphicPtr;
    typedef std::shared_ptr<DlLoaderGame> DlLoaderGamePtr;
}
