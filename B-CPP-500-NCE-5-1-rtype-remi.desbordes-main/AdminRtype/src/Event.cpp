#include "Event.hpp"
#include "factory/factory.hpp"

bool Event::check_click(Entity entity, sf::Event event, sf::Mouse mouse)
{      
    if (entity.has<component::Clickable>() and event.type == sf::Event::MouseButtonReleased
        and entity.get<component::Sprite>().get_pos().x <= mouse.getPosition().x
        and mouse.getPosition().x <= entity.get<component::Sprite>().get_size().x + entity.get<component::Sprite>().get_pos().x
        and entity.get<component::Sprite>().get_pos().y <= mouse.getPosition().y and mouse.getPosition().y <=
        entity.get<component::Sprite>().get_size().y + entity.get<component::Sprite>().get_pos().y)
            return true;
    return false;
}