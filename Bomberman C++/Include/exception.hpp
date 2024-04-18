/*
** EPITECH PROJECT, 2022
** Exception.hpp
** File description:
** Exception class for Indie Studio.
*/

#include <cstddef>
#include <iostream>
#include <array>

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

class my_exception : public std::exception
{
    public:
      virtual const char* what() const throw() { return ("USAGE: ./bomberman\n      You just need to launch the game without arguments!"); };
};

#endif
