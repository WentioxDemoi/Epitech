#pragma once

namespace component
{
    class Enemy
    {
        public:
            Enemy(std::vector<std::vector<float>> info);
            ~Enemy() {};
            bool get_go_letf(void) const;
            bool get_go_down(void) const;
            void set_go_letf(bool status);
            void set_go_down(bool status);
            std::vector<float> get_min_placement(void) const;
            std::vector<float> get_max_placement(void) const;
            std::vector<float> get_origin_pos(void) const;
            std::vector<float> get_speed(void) const;
            void  set_min_placement(std::vector<float> min_placement);
            void set_max_placement(std::vector<float> max_placement);
            void set_origin_pos(std::vector<float> pos);
            void set_speed(std::vector<float> speed);
            void update_pos_x(float speed);
            void update_pos_y(float speed);
            void kill_enemy(Entity e);
        private:
            bool go_left;
            bool go_down;
            std::vector<float> min_placement;
            std::vector<float> max_placement;
            std::vector<float> origin_pos;
            std::vector<float> speed;
    };
};