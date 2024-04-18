#include "shoot.hpp"
#include "enemy.hpp"
#include "sprite.hpp"

component::Shoot::Shoot(std::string spritepath)
{
    if (!_texture.loadFromFile(spritepath))
        return;
    _size.x = _texture.getSize().x * 0.5;
    _size.y = _texture.getSize().y * 0.5;
    _sprite.rotate(90);
    _sprite.setTexture(_texture, false);
    _sprite.setScale(0.5, 0.5);
}

void component::Shoot::create_bullet(std::vector<float> pos)
{
        _pos.x = pos[0];
        _pos.y = pos[1];
        _sprite.setPosition(sf::Vector2f(_pos.x, _pos.y));
}

sf::Sprite component::Shoot::get_sprite(void) const
{
    return _sprite;
}