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
            Core(const std::shared_ptr<std::vector<Arcade::DlLoaderGraphicPtr>>& graphicLibsLoader,
                const std::shared_ptr<std::vector<Arcade::DlLoaderGamePtr>>& gameLibsLoader,
                Arcade::StringVectorPtr libs, Arcade::StringVectorPtr games);
            ~Core();
            void addGraphicLib(const Arcade::IGraphicLibPtr& lib);
            std::shared_ptr<std::vector<Arcade::IGraphicLibPtr>> getGraphicLibs() const;
            void addGameLib(const Arcade::IGameLibPtr& lib);
            std::shared_ptr<std::vector<Arcade::IGameLibPtr>> getGameLibs() const;
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
            void getGraphicalInstances(const std::shared_ptr<std::vector<Arcade::DlLoaderGraphicPtr>>& graphicLibs);
            void getGameInstances(const std::shared_ptr<std::vector<Arcade::DlLoaderGamePtr>>& gameLibs);
            void createMainMenu(const StringVectorPtr& libsName, const StringVectorPtr& gamesName);
            void logicalMenu();
            enum CoreState getState() const;
            void setState(enum CoreState state);
            Arcade::IObjectVector getGameObjects() const;
        protected:
            std::shared_ptr<std::vector<Arcade::IGraphicLibPtr>> _graphicLibs;
            std::shared_ptr<std::vector<Arcade::IGameLibPtr>> _gamesLibs;
            bool _isRunning;
            int _currentGame;
            int _currentLib;
            int _tempLib;
            int _tempGame;
            enum CoreState _state;
            Arcade::windowsParameter_t _windowsParameter{};
            Arcade::IObjectVector _gameObjects;
            Arcade::IObjectVector _menuObjects;
            Arcade::StringVectorPtr _libsName;
            Arcade::StringVectorPtr _gamesName;
        private:
    };

}