/*
** EPITECH PROJECT, 2022
** Logo.cpp
** File description:
** Logo file for Indie Studio.
*/

#include "../Include/Logo/Logo.hpp"

Logo::Logo()
{
    logoPositionX = 1920/2 - 128;
    logoPositionY = 1080/2 - 128;

    framesCounter = 0;
    lettersCount = 0;

    topSideRecWidth = 16;
    leftSideRecHeight = 16;

    bottomSideRecWidth = 16;
    rightSideRecHeight = 16;

    state = 0;
    state_letter = 0;
    alpha = 1.0f; 
}

Logo::~Logo()
{

}

void Logo::init_logo()
{
    _sound.push_back(Sound_G(0.7, "Ressources/Sound/logo.wav"));
    _shader.push_back(Shader_Indie("Ressources/Shaders/wave.fs"));
    _shader[0].value_shader();
}

void Logo::shader_timer()
{
    _shader[0].timer_shader();
}

int Logo::Logo_Loader()
{
        if (IsKeyPressed(KEY_ENTER))
        {
           return (0);
        }

        if (state == 0)
        {
            framesCounter++;

            if (framesCounter == 120)
            {
                state = 1;
                framesCounter = 0;
            }
        }
        else if (state == 1)
        {
            topSideRecWidth += 6;
            leftSideRecHeight += 6;

            if (topSideRecWidth == 256) state = 2;
        }
        else if (state == 2)
        {
            bottomSideRecWidth += 4;
            rightSideRecHeight += 4;

            if (bottomSideRecWidth == 256) state = 3;
        }
        else if (state == 3) {
            framesCounter++;

            if (framesCounter/14) {
                lettersCount++;
                framesCounter = 0;
            }

            if (lettersCount >= 12) {
                alpha -= 0.01f;

                if (alpha <= 0.01f)
                    _sound[0].play_audio();

                if (alpha <= 0.0f) {
                    alpha = 0.0f;
                    state = 4;
                }
            }
        } else if (state == 4) {
            state = 5;
        }
        
        _shader[0].draw_shader();

            if (state == 0)
            {
                if ((framesCounter/15)%2) DrawRectangle(logoPositionX, logoPositionY, 16, 16, Fade(RED, alpha));
            }
            else if (state == 1)
            {
                DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, RED);
                DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, BLUE);
            }
            else if (state == 2)
            {
                DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, RED);
                DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, BLUE);

                DrawRectangle(logoPositionX + 240, logoPositionY, 16, rightSideRecHeight, GREEN);
                DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, GRAY);
            }
            else if (state == 3)
            {
                DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, Fade(RED, alpha));
                DrawRectangle(logoPositionX, logoPositionY + 16, 16, leftSideRecHeight - 32, Fade(BLUE, alpha));

                DrawRectangle(logoPositionX + 240, logoPositionY + 16, 16, rightSideRecHeight - 32, Fade(GREEN, alpha));
                DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, Fade(GRAY, alpha));

                DrawRectangle(GetScreenWidth()/2 - 112, GetScreenHeight()/2 - 112, 224, 224, Fade(BLACK, alpha));

                DrawText(TextSubtext("Indie Studio", 0, lettersCount), GetScreenWidth()/2 - 44, GetScreenHeight()/2 + 48, 25, Fade(WHITE, alpha));

            }
            else if (state == 4)
            {
            }
            else if (state == 5)
            {
                return (0);
            }
            _shader[0].stop_shader();
    return (42);
}