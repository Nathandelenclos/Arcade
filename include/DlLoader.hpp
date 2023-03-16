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

namespace Arcade {
    template<typename Loader>
    class DlLoader {
        public:
            class LibError : public std::exception {
                public:
                    explicit LibError(const std::string &msg) : _msg(msg)
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
                    throw LibError("Cannot open Libfoo Library: ");
            }

            ~DlLoader()
            {
                if (_handle)
                    dlclose(_handle);
            }

            std::shared_ptr<Loader> getInstance()
            {
                std::shared_ptr<Arcade::IGraphicLib> lib;
                auto entryPoint = dlsym(_handle, "constructor_graphic");

                if (!entryPoint)
                    throw LibError("Cannot load symbol 'constructor_graphic': ");
                auto *(*libfoo)() = (Arcade::IGraphicLib *(*)()) entryPoint;
                lib = std::shared_ptr<Arcade::IGraphicLib>(libfoo());

                if (!lib)
                    throw LibError("Cannot load symbol 'constructor_graphic': ");
                return (lib);
            }

        protected:
            void *_handle;
    };
}
