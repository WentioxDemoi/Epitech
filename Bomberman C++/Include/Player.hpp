#pragma once
#include "VirtualClass/IDraw.hpp"
#include "VirtualClass/ICollidable.hpp"
#include "Bomb.hpp"
#include "raymath.h"
#include <cstring>
#include <vector>

#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

class Player : public IDraw, public ICollidable
{
    public:
        Player(Vector3 pos, float size, const std::string& name);
        bool IsinLife(){if(_life > 0) return true; else return false;};
        void LoadingModel_Among();
        void draw() override;        
        void among_event(int);
        void ia_event(int, std::vector<Player> &players);
        void ia_up();
        void ia_down();
        void ia_left();
        void ia_right();
        void update() override {};
        bool IsCollide(ICollidable &other) override;
        const ICollidable &getCollidable() const override;
        bool getcollide(bool) { return _collide; };
        Vector3 &getCollidable_pos() override {return _position;};
        void emplace_bomb(double time, std::vector<Cube> &cubes_map, std::vector<Player> &players, int);
        void setModel(int color);
        float _scale;
        Vector3 _position;
        bool _collide;
        int _color;
    private:
        std::vector<std::string> _model_path;
        std::vector<std::vector<Model>> _model;
        std::vector<Bomb> bombs;
        std::string _model_path_red;
        std::string _model_path_blue;
        std::string _model_path_black;
        std::string _model_path_green;
        std::string _name;
        Vector3 _rotation;
        int xc;
        int xz;
        int y;
        float _pitch;
        float _yaw;
        float _roll;
        float _velocity;
        double _tmp_time;
        int _color_model;
        bool _ia_bomb;

        int _left;
        int _right;
        int _up;
        int _down;
        int _tmp = 0;
        int _life;

        Color _Color;
};


#endif /* _PLAYER_HPP_ */
