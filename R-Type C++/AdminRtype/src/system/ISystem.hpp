#pragma once

#include "../Entity.hpp"

namespace my_system
{
    class ISystem
    {
        public:
            virtual ~ISystem() {};
            virtual void process(Entity &entity) = 0;
    };
};