/*
** EPITECH PROJECT, 2022
** IHover.hpp
** File description:
** IHover class for Indie Studio.
*/

#include "raylib.h"

#ifndef _IHOVER_HPP_
#define _IHOVER_HPP_

class IHover {
    public:
        virtual bool isHover() const = 0;
        virtual void onHover() = 0;
};

#endif /* _IHOVER_HPP_ */

