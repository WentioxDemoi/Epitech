/*
** EPITECH PROJECT, 2022
** Main.cpp
** File description:
** Main function for Indie Studio.
*/

#include "../Include/Tools.hpp"
#include "../Include/Core/Core.hpp"

int main(int ac, char **av)
{
    Core core;

    try {
      core.Erroring(ac);
      core.Launching_Game(ac);
    }
    catch (std::exception const &e) {
      std::cerr << e.what() << std::endl;
      return (84);
    }
}

