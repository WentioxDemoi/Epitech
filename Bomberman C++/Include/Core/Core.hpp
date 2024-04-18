/*
** EPITECH PROJECT, 2022
** Core.hpp
** File description:
** Core class for Indie Studio.
*/

#include <iostream>
#include <string.h>
#include <cstring>
#include "../Include/exception.hpp"
#include "raylib.h"

#ifndef Core_H_
#define Core_H_

class Core {
    public:
        Core();
        ~Core();
        void Erroring(int ac);
        int Launching_Game(int ac);
    private:
        typedef enum GameScreen {
            MENU = 0,
            PLAY = 1,
            HOW_TO_PLAY = 2,
            OPTION = 3,
            QUIT = 4,
            AUDIO = 5,
            GRAPHICS = 6,
            OBJECTIVES = 7,
            BEFORE_PLAY = 8,
            GAME = 9,
            PAUSE = 10,
            VICTORY = 11,
            LOOSE = 12,
            LOGO = 42,
        } GameScreen;
      GameScreen currentScreen;
      int _fps;
      int _health_player;
      int _health_green;
      int _health_blue;
      int _health_black;
      std::string _name;
};

#endif