#include "Entity.hpp"
#include "system/magicsystem.hpp"

int main(void)
{
    my_system::MagicSystem core(1920, 1080, "N  Y  R  E  A");

    core.initialization();
    core.run();
}