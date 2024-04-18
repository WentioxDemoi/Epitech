/*
** EPITECH PROJECT, 2022
** IDraw.hpp
** File description:
** IDraw class for Indie Studio.
*/

#include "raylib.h"
#include <vector>
#include <string>
#include <iostream>
#include <ostream>

#ifndef _IDRAW_HPP_
#define _IDRAW_HPP_

class IDraw {
    public:
        virtual void draw() = 0;
        virtual void update() = 0;
};

#endif
