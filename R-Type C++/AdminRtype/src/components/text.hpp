#pragma once

#include "../system/ISystem.hpp"

namespace component
{
    class Text_R {
    public:
        Text_R() = default;
        Text_R(float x, float y, unsigned int size, std::string font_path, std::string text);
        ~Text_R();
        sf::Text get_text(void) const;
        std::string get_string(void) const;
        void set_color(sf::Uint8 red, sf::Uint8 green, sf::Uint8 blue, sf::Uint8 alpha_transparency);
        void update_text(std::string new_text);
        void update_pos(float x, float y);
        void update_size(unsigned int new_size);
        void update_font(std::string new_font_path);
        void input_text(sf::Event &event, int max_char, float size_ratio, bool digit_mode, bool ip_mode);
    private:
        sf::Text _text;
        sf::Font _font;
        float pos_x;
        float pos_y;
        unsigned int _size;
        std::string text;
    };
}