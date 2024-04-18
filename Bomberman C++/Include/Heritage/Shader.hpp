/*
** EPITECH PROJECT, 2022
** Shader.hpp
** File description:
** Shader class for Indie Studio.
*/

#include "../Include/VirtualClass/IShader.hpp"

#ifndef _SHADERINDIE_HPP_
#define _SHADERINDIE_HPP_

class Shader_Indie : public IShader {
    public:
        Shader_Indie(const std::string& path);
        ~Shader_Indie() {};
        void timer_shader();
        void value_shader();
        void draw_shader();
        void stop_shader();
    private:
        Shader _shader;
        float seconds = 0.0f;
        int _secondsLoc;
};

#endif