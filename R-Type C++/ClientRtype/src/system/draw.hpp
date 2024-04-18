#pragma once

#include "ISystem.hpp"

namespace my_system
{
    class Draw : public ISystem
    {
        public:
            Draw() = default;
            ~Draw() {}
            void process(Entity &entity);
    };
};