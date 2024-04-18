
#include "Heritage/Cube.hpp"
#include "../Include/Heritage/Sound.hpp"

#ifndef _IBomb_HPP_
#define _IBomb_HPP_


class Bomb : public IDraw, public ICollidable {
    public:
        Bomb(Vector3, Vector3 size, const std::string& path);
        void explode(int);
        void end_explode();
        void boom_sound();
        void draw() override;
        void draw_model();
        void update() override {};
        void Init_Sound_Game();
        Vector3 getPos() { return _position; };
        bool IsCollide(ICollidable &other) override;
        const ICollidable &getCollidable() const override{return *this;};
        Vector3 &getCollidable_pos() override {return _position;};
        void setPos(Vector3 pos) { _position = pos; };
        void clean_list();
        ~Bomb() {};
        std::vector<Cube> _cube_explode_up;
        std::vector<Cube> _cube_explode_down;
        std::vector<Cube> _cube_explode_left;
        std::vector<Cube> _cube_explode_right;
        bool _collide;
    private:
        std::vector<Sound_G> _sound;
        Vector3 _position;
        Vector3 _size;
        Texture2D _texture;
        Model _model;
        Color _color = RED;
        float _scale = 2.0f;
};

#endif