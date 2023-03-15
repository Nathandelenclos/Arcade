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

template <typename Loader>
class DlLoader {
    public:
        class LibError : public std::exception {
            public:
                explicit LibError(const std::string &msg) : _msg(msg) {};
                const char *what() const noexcept override {
                    return (_msg.c_str());
                }
            protected:
                const std::string _msg;
        };

        explicit DlLoader(const std::string &path) : _handle(dlopen(path.c_str(), RTLD_LAZY)) {
            if (!_handle)
                throw LibError("Cannot open Libfoo Library: ");
        }
        ~DlLoader() {
            if (_handle)
                dlclose(_handle);
        }

        Loader *getInstance() {
            std::shared_ptr<IDisplayModule> lib;
            auto entryPoint= dlsym(_handle, "entryPoint");

            if (!entryPoint)
                throw LibError("Cannot load symbol 'entryPoint': ");
            auto *(*libfoo)() = (IDisplayModule *(*)())entryPoint;
            lib = std::shared_ptr<IDisplayModule>(libfoo());

            if (!lib)
                throw LibError("Cannot load symbol 'entryPoint': ");
            return (lib);
        }
    protected:
        void *_handle;
};
