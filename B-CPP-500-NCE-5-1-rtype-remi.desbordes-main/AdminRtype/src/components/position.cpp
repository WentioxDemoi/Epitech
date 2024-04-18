#include "position.hpp"

component::Position::Position(float x, float y)
{
    this->_pos.x = x;
    this->_pos.y = y;
}

component::Position::~Position()
{
}

void component::Position::update_pos(float x, float y)
{
    this->_pos.x += x;
    this->_pos.y += y;
}

sf::Vector2f component::Position::get_pos(void) const
{
    return (this->_pos);
}