#include "factory.hpp"

Entity Factory::create_sprite(std::string spritepath, float x, float y, float s)
{
    Entity object;

    object.set<component::Position>(x, y);
    object.set<component::Draw>();
    object.set<component::Sprite>(spritepath, x, y, s);
    return object;
}

Entity Factory::create_parallax(std::string spritepath, float x, float y, float s, float parallax)
{
    Entity object;

    object.set<component::Position>(x, y);
    object.set<component::Draw>();
    object.set<component::Sprite>(spritepath, x, y, s);
    object.set<component::Parallax>(parallax);
    return object;
}

Entity Factory::create_button(std::string spritepath, std::string button_name, float x, float y, float s)
{ 
    Entity object;

    object.set<component::Position>(x, y);
    object.set<component::Draw>();
    object.set<component::Sprite>(spritepath, x, y, s);
    object.set<component::Clickable>(button_name);
    return object;
}

Entity Factory::create_text(float x, float y, unsigned int size, std::string font_path, std::string text)
{
    Entity object;

    object.set<component::Position>(x, y);
    object.set<component::Draw>();
    object.set<component::Text_R>(x, y, size, font_path, text);
    return object;
}

Entity Factory::create_player(std::string spritepath, float x, float y, float s, std::string dir_path, int max_frame)
{
    Entity object;

    object.set<component::Position>(x, y);
    object.set<component::Draw>();
    object.set<component::Sprite>(spritepath, x, y, s);
    object.set<component::Animation>(dir_path, max_frame);
    return object;
}

Entity Factory::create_enemy(std::vector<std::vector<float>> info)
{
    Entity object;

    object.set<component::Position>(info[2][0], info[2][1]);
    object.set<component::Draw>();
    object.set<component::Sprite>("Assets/Images/Enemies/Ship_01.png", info[2][0], info[2][1], 0.15);
    object.set<component::Collision>();
    object.set<component::Enemy>(info);
    return object;
}

Entity Factory::create_music(std::string music_path, bool loop)
{
    Entity object;

    object.set<component::Music>(music_path, loop);
    return object;
}

Entity Factory::create_shoot(std::string bullet_path)
{
    Entity object;

    object.set<component::Shoot>(bullet_path);
    return object;
}

Entity Factory::create_hunter_re(std::string spritepath, float x, float y, float s)
{
    Entity object;

    object.set<component::Position>(x, y);
    object.set<component::Draw>();
    object.set<component::Sprite>(spritepath, x, y, s);
    object.set<component::Clickable>("hunter_re");
    return object;
}