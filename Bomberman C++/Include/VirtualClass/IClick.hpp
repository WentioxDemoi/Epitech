/*
** EPITECH PROJECT, 2022
** IClick.hpp
** File description:
** IClick class for Indie Studio.
*/

#ifndef _IClick_HPP_
#define _IClick_HPP_

class IClick {
    public:
        virtual bool isClicked() const = 0;
        virtual void onClick() = 0;
};

#endif