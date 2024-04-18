#include "draw.hpp"
#include "../components/draw.hpp"
#include "../components/position.hpp"
#include "../components/sprite.hpp"

void my_system::Draw::process(Entity &entity)
{
    if (entity.has<component::Draw>() and entity.has<component::Position>()
        and entity.has<component::Sprite>()) {
        auto &draw = entity.get<component::Draw>();
        auto &position = entity.get<component::Position>();
        auto &sprite = entity.get<component::Sprite>();
    }
}