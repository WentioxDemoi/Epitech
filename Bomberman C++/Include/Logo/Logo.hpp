/*
** EPITECH PROJECT, 2022
** Logo.hpp
** File description:
** Logo class for Indie Studio.
*/

#include "../Include/Heritage/Sound.hpp"
#include "../Include/Heritage/Shader.hpp"
#include <string.h>
#include <fstream>
#include <vector>

#ifndef _LOGO_HPP_
#define _LOGO_HPP_

class Logo {
    public:
        Logo();
        ~Logo();
        int Logo_Loader();
        void init_logo();
        void shader_timer();
    private:
        std::vector<Sound_G> _sound;
        std::vector<Shader_Indie> _shader;

        int logoPositionX;
        int logoPositionY;

        int framesCounter;
        int lettersCount;

        int topSideRecWidth;
        int leftSideRecHeight;

        int bottomSideRecWidth;
        int rightSideRecHeight;

        int state;
        int state_letter;
        
        float alpha;
};

#endif