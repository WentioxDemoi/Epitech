#include "sprite.hpp"

component::Sprite::Sprite(std::string spritepath, float x, float y, float s)
{
    if (!_texture.loadFromFile(spritepath))
        return;
    _pos.x = x;
    _pos.y = y;
    _size.x = _texture.getSize().x * s;
    _size.y = _texture.getSize().y * s;
    _sprite.setTexture(_texture, false);
    _sprite.setScale(s, s);
    _sprite.setPosition(sf::Vector2f(x, y));
}

void component::Sprite::set_color(sf::Uint8 red, sf::Uint8 green, sf::Uint8 blue, sf::Uint8 alpha_transparency)
{
    _sprite.setColor(sf::Color(red, green, blue, alpha_transparency));
}

void component::Sprite::update_texture(std::string spritepath)
{
    if (!_texture.loadFromFile(spritepath))
        return;
    _sprite.setTexture(_texture, false);
}

sf::Vector2f component::Sprite::get_pos(void) const
{
    return _pos;
}

void component::Sprite::set_pos(float x, float y)
{
    _pos.x = x;
    _pos.y = y;
    _sprite.setPosition(_pos.x, _pos.y);
}

void component::Sprite::update_pos(sf::Vector2f n_pos)
{
    _pos.x += n_pos.x;
    _pos.y += n_pos.y;
    _sprite.setPosition(_pos.x, _pos.y);
}

void component::Sprite::update_move(sf::Vector2f move)
{
    _pos.x += move.x;
    _pos.y += move.y;
    _sprite.move(move.x, move.y);
}

sf::Vector2f component::Sprite::get_size(void) const
{
    return _size;
}

sf::Sprite component::Sprite::get_spr(void) const
{
    return this->_sprite;
}