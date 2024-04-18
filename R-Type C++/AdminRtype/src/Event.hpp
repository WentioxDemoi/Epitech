#pragma once

#include "Entity.hpp"

class Event {
    public:
        Event() {};
        ~Event() {};
        bool check_click(Entity entity, sf::Event event, sf::Mouse mouse);
    private:
};