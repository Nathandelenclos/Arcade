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

    typedef struct {
        std::string character;
        InputKey inputKey;
    } keyMatching;

    static keyMatching matching[] {
            {"a", InputKey::KEY_A},
            {"b", InputKey::KEY_B},
            {"c", InputKey::KEY_C},
            {"d", InputKey::KEY_D},
            {"e", InputKey::KEY_E},
            {"f", InputKey::KEY_F},
            {"g", InputKey::KEY_G},
            {"h", InputKey::KEY_H},
            {"i", InputKey::KEY_I},
            {"j", InputKey::KEY_J},
            {"k", InputKey::KEY_K},
            {"l", InputKey::KEY_L},
            {"m", InputKey::KEY_M},
            {"n", InputKey::KEY_N},
            {"o", InputKey::KEY_O},
            {"p", InputKey::KEY_P},
            {"q", InputKey::KEY_Q},
            {"r", InputKey::KEY_R},
            {"s", InputKey::KEY_S},
            {"t", InputKey::KEY_T},
            {"u", InputKey::KEY_U},
            {"v", InputKey::KEY_V},
            {"w", InputKey::KEY_W},
            {"x", InputKey::KEY_X},
            {"y", InputKey::KEY_Y},
            {"z", InputKey::KEY_Z},
            {" ", InputKey::SPACE},
            {"", InputKey::BackSpace},
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
            void printInput();
            Arcade::IObjectVector getGameObjects() const;
            std::string getUsername() const;
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
            std::string _username;
            Arcade::windowsParameter_t _windowsParameter;
            Arcade::IObjectVector _gameObjects;
            Arcade::IObjectVector _menuObjects;
            Arcade::StringVectorPtr _libsName;
            Arcade::StringVectorPtr _gamesName;
            int _charNbr;
        private:
    };

}