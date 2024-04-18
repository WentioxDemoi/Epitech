#include "text.hpp"

component::Text_R::Text_R(float x, float y, unsigned int size, std::string font_path, std::string text)
{
    this->_pos.x = x;
    this->_pos.y = y;
    this->_size = size;
    this->_font.loadFromFile(font_path);
    this->_text.setFont(this->_font);
    this->_text.setString(text);
    this->_text.setCharacterSize(this->_size);
    this->_text.setPosition(this->_pos.x, this->_pos.y);
}

sf::Text component::Text_R::get_text(void) const
{
    return _text;
}

std::string component::Text_R::get_string(void) const
{
    return text;
}

sf::Vector2f component::Text_R::get_pos(void) const
{
    return _pos;
}

void component::Text_R::set_string(std::string str)
{
    this->_text.setString(str);
}

void component::Text_R::set_color(sf::Uint8 red, sf::Uint8 green, sf::Uint8 blue, sf::Uint8 alpha_transparency)
{
    sf::Color transparent = sf::Color(red, green, blue, alpha_transparency);
    this->_text.setFillColor(transparent);
}

void component::Text_R::update_text(std::string new_text)
{
    this->text = new_text;
    this->_text.setString(this->text);
}

void component::Text_R::update_pos(float x, float y)
{
    this->_pos.x = x;
    this->_pos.y = y;
    this->_text.setPosition(this->_pos.x, this->_pos.y);
}

void component::Text_R::update_size(unsigned int new_size)
{
    this->_size = new_size;
    this->_text.setCharacterSize(this->_size);
}

void component::Text_R::update_font(std::string new_font_path)
{
    this->_font.loadFromFile(new_font_path);
    this->_text.setFont(this->_font);
}

void component::Text_R::input_text(sf::Event &event, int max_char, float size_ratio, bool digit_mode, bool ip_mode)
{
    if (event.type == sf::Event::TextEntered)
    {
        if (!digit_mode && !ip_mode) {
            if ((event.text.unicode <= 125 && event.text.unicode >= 32) && this->text.size() < max_char)
                this->text += event.text.unicode;
        } else if (digit_mode && !ip_mode) {
            if ((event.text.unicode >= 48 && event.text.unicode <= 57) && this->text.size() < max_char)
                this->text += event.text.unicode;
        }
        if (ip_mode) {
            if ((event.text.unicode >= 48 && event.text.unicode <= 57 || event.text.unicode == 46) && this->text.size() < max_char)
                this->text += event.text.unicode;
            if (event.text.unicode == 8) {
                if (this->text.size() >= 1)
                    this->text.pop_back();
            }
        }
        else {
            if (event.text.unicode == 8)
                if (this->text.size() >= 1)
                    this->text.pop_back();
        }
        update_size(100 - (this->text.size() / size_ratio));
        update_text(this->text);
    }
}