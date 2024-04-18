/*
** EPITECH PROJECT, 2022
** Shader.cpp
** File description:
** Shader file for Indie Studio.
*/

#include "../Include/Heritage/Shader.hpp"

Shader_Indie::Shader_Indie(const std::string& path)
{
    _shader = LoadShader(0, TextFormat(path.c_str(), GLSL_VERSION));
}

void Shader_Indie::value_shader()
{
    float screenSize[2] = { 1920, 1080 };

    _secondsLoc = GetShaderLocation(_shader, "secondes");
    int freqXLoc = GetShaderLocation(_shader, "freqX");
    int freqYLoc = GetShaderLocation(_shader, "freqY");
    int ampXLoc = GetShaderLocation(_shader, "ampX");
    int ampYLoc = GetShaderLocation(_shader, "ampY");
    int speedXLoc = GetShaderLocation(_shader, "speedX");
    int speedYLoc = GetShaderLocation(_shader, "speedY");

    float freqX = 25.0f;
    float freqY = 25.0f;
    float ampX = 3.0f;
    float ampY = 3.0f;
    float speedX = 2.0f;
    float speedY = 2.0f;

    SetShaderValue(_shader, GetShaderLocation(_shader, "size"), &screenSize, SHADER_UNIFORM_VEC2);
    SetShaderValue(_shader, freqXLoc, &freqX, SHADER_UNIFORM_FLOAT);
    SetShaderValue(_shader, freqYLoc, &freqY, SHADER_UNIFORM_FLOAT);
    SetShaderValue(_shader, ampXLoc, &ampX, SHADER_UNIFORM_FLOAT);
    SetShaderValue(_shader, ampYLoc, &ampY, SHADER_UNIFORM_FLOAT);
    SetShaderValue(_shader, speedXLoc, &speedX, SHADER_UNIFORM_FLOAT);
    SetShaderValue(_shader, speedYLoc, &speedY, SHADER_UNIFORM_FLOAT);
}

void Shader_Indie::draw_shader()
{
    BeginShaderMode(_shader);
}

void Shader_Indie::stop_shader()
{
    EndShaderMode();
}

void Shader_Indie::timer_shader()
{
    seconds += GetFrameTime();

    SetShaderValue(_shader, _secondsLoc, &seconds, SHADER_UNIFORM_FLOAT);
}