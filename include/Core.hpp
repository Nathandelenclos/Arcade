/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** DlLoader.hpp
*/

#pragma once

#include <memory>
#include <utility>
#include <vector>
#include "IGraphicLib.hpp"
#include "IGameLib.hpp"
#include "Types.hpp"
#include "Types.hpp"
#include "DlLoader.hpp"
#include "Text.hpp"
#include "Entity.hpp"
#include "Button.hpp"
#include "DlLoader.hpp"

namespace Arcade {
    typedef std::shared_ptr<std::vector<std::string>> StringVectorPtr;

    enum class CoreState {
        MENU,
        GAME,
        EXIT
    };

    class Core {
        public:
            Core();
            Core(const std::string &lib, const Arcade::StringVectorPtr& libs, const Arcade::StringVectorPtr& games);
            ~Core();
            IGraphicLibPtr getCurrentGraphicLib() const;
            IGameLibPtr getCurrentGameLib() const;
            void setCurrentGraphicLib(int index);
            void setCurrentGameLib(int index);
            void switchGraphicLib();
            void switchGameLib();
            void startGraphic();
            void stopGraphic() const;
            bool isRunning() const;
            void setRunning(bool isRunning);
            void makeGameInstance(int index);
            void makeLibInstance(int index);
            void createMainMenu(const StringVectorPtr& libsName, const StringVectorPtr& gamesName);
            void logicalMenu();
            enum CoreState getState() const;
            void setState(enum CoreState state);
            Arcade::IObjectVector getGameObjects() const;
        protected:
            Arcade::DlLoaderGraphicPtr _libLoader;
            Arcade::DlLoaderGamePtr _gameLoader;
            IGraphicLibPtr _currentLib;
            IGameLibPtr _currentGame;
            bool _isRunning;
            int _currentGameIndex;
            int _tempGameIndex;
            int _currentLibIndex;
            int _tempLibIndex;
            enum CoreState _state;
            Arcade::windowsParameter_t _windowsParameter{};
            Arcade::IObjectVector _gameObjects;
            Arcade::IObjectVector _menuObjects;
            Arcade::StringVectorPtr _libsName;
            Arcade::StringVectorPtr _gamesName;
        private:
    };

}