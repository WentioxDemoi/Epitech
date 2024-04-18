/*
** EPITECH PROJECT, 2022
** Player.cpp
** File description:
** Player functions for Indie Studio.
*/

#include "../../Include/Player.hpp"

Player::Player(Vector3 pos, float size, const std::string& name) {
    _life = 1;
    _pitch = -90.0f;
    _yaw = 0.0f;
    _roll = 0.0f;
    _position = pos;
    _rotation = Vector3{ 0.0f, 0.0f, 0.0f };
    _scale = size;
    _name = name;
    _model_path_red =   "Among_us/Among_us_red/Amongus_000001.obj";
    _model_path_blue =  "Among_us/Among_us_blue/Amongus_000001.obj";
    _model_path_black = "Among_us/Among_us_black/Amongus_000001.obj";
    _model_path_green = "Among_us/Among_us_green/Amongus_000001.obj"; 
    y = 0, xc = 0, xz = 0;
    _left = 0, _right = 0, _up = 0, _down = 0;
    _color = 0;
    _collide = false;
    _velocity = 0.1f;
    _ia_bomb = false;
    LoadingModel_Among();
};

void Player::setModel(int color)
{
    _color_model = color;
}

void Player::LoadingModel_Among()
{
    _model_path.push_back(_model_path_red);
    _model_path.push_back(_model_path_blue);
    _model_path.push_back(_model_path_black);
    _model_path.push_back(_model_path_green);
    for (int i = 0; i != _model_path.size(); i++) {
        _model.emplace_back();
        y = 0;
        while (y != 15) {
            _model.at(i).emplace_back(LoadModel(_model_path.at(i).c_str())); 
            if (_model_path.at(i).at(strlen(_model_path.at(i).c_str()) - 5) == '9') {
                _model_path.at(i).at(strlen(_model_path.at(i).c_str())-6) += 1;
                _model_path.at(i).at(strlen(_model_path.at(i).c_str())-5) = '0';
            } else
                _model_path.at(i).at(strlen(_model_path.at(i).c_str())-5) += 1;
            y++;
        }
    }
}

void Player::draw()
{  
    if (xc == 14)
        xc = 0;
    switch (_color_model) {
        case 0:{_Color = RED;}break; 
        case 1:{_Color = SKYBLUE;}break;
        case 2:{_Color = LIME;}break;
        case 3:{_Color = DARKGRAY;}break;
        default:{_Color = RED;}break;}
    _model.at(_color_model).at(xc).transform = MatrixRotateXYZ(Vector3{ DEG2RAD*_pitch, DEG2RAD*_yaw, DEG2RAD*_roll });
    if (_life > 0)
        DrawModel(_model.at(_color_model).at(xc), {_position.x, _position.y, _position.z-0.5f}, _scale, _Color);
}

void Player::among_event(int player) {
    if ((IsKeyDown(KEY_RIGHT) && player == 0) || (IsKeyDown(KEY_D) && player == 3)) {
        _roll = -90;
        if (_collide && _right == 1) {
            _position.x -= _velocity;
            _right = 2;
            xc = 0;
            return;
        } else if (_right == 2)
            return;
        xc++;
        _collide = false;
        _right = 1, _left = 0, _up = 0, _down = 0;
        _position.x += _velocity;
    }
    else if ((IsKeyDown(KEY_LEFT) && player == 0) || (IsKeyDown(KEY_A) && player ==3)) {
        
        _roll = 90;
        if (_collide && _left == 1) {
            _position.x += _velocity;
            _left = 2;
            xc = 0;
            return;
        } else if (_left == 2)
            return;
        xc++;
        _collide = false;
        _right = 0, _left = 1, _up = 0, _down = 0;
        _position.x -= _velocity;
    }
    else if ((IsKeyDown(KEY_UP) && player == 0) || (IsKeyDown(KEY_W) && player == 3)) {
        _roll = 180;
        if (_collide && _up == 1) {
            _position.y -= _velocity;
            _up = 2;
            xc = 0;
            return;
        } else if (_up == 2)
            return;
        xc++;
        _collide = false;
        _right = 0, _left = 0, _up = 1, _down = 0;
        _position.y += _velocity;
    }
    else if ((IsKeyDown(KEY_DOWN) && player == 0) || (IsKeyDown(KEY_S) && player == 3)) {
        _roll = 0;
        if (_collide && _down == 1) {
            _position.y += _velocity;
            _down = 2;
            xc = 0;
            return;
        } else if (_down == 2)
            return;
        xc++;
        _collide = false;
        _right = 0, _left = 0, _up = 0, _down = 1;
        _position.y -= _velocity;
    }
}

void Player::ia_event(int player, std::vector<Player> &players)
{
    if (player == 1)
        _roll -= 2;
    if (player == 2)
        _roll += 2;

}


bool Player::IsCollide(Player::ICollidable &other) {
    if (CheckCollisionBoxes(
            BoundingBox{ Vector3{ _position.x - 0.7f/2,
                                     _position.y - 0.7f/2,
                                     _position.z - 0.7f/2 },
                           Vector3{ _position.x + 0.7f/2,
                                     _position.y + 0.7f/2,
                                     _position.z + 0.7f/2 }},
            BoundingBox{ Vector3{ other.getCollidable_pos().x - 0.7f/2,
                                     other.getCollidable_pos().y - 0.7f/2,
                                     other.getCollidable_pos().z - 0.7f/2 },
                           Vector3{ other.getCollidable_pos().x + 0.7f/2,
                                     other.getCollidable_pos().y + 0.7f/2,
                                     other.getCollidable_pos().z + 0.7f/2}})) _collide = true;
    return _collide;
}
const Player::ICollidable &Player::getCollidable() const {
    return *this;
}

void Player::emplace_bomb(double time, std::vector<Cube> &cubes_map, std::vector<Player> &players, int player)
{
    if ((player == 1 && _tmp == 0 && _life > 0 && (cubes_map.at(26).getCollidable_pos().z == 0 || cubes_map.at(58).getCollidable_pos().z == 0)) ||
    (player == 2 && _tmp == 0 && _life > 0 && (cubes_map.at(168).getCollidable_pos().z == 0 || cubes_map.at(136).getCollidable_pos().z == 0))) {
        _tmp_time = time;
        bombs.emplace_back(_position, Vector3{0.6f,0.6f,0.6f}, "Among_us/Bomb/Bomb.obj");
        if (_tmp == 0){
            bombs.at(0).explode(2);
            _tmp = 1;
        }
    }
     if ((IsKeyPressed(KEY_SPACE) && player==3) || (IsKeyPressed(KEY_ENTER) && player==0)  && _tmp == 0 && _life > 0) {
        _tmp_time = time;
        bombs.emplace_back(_position, Vector3{0.6f,0.6f,0.6f}, "Among_us/Bomb/Bomb.obj");
        if (_tmp == 0){
            bombs.at(0).explode(2);
            _tmp = 1;
        }
    }
 
    
    if (_tmp == 1 || _tmp == 2) {
        bombs[0].draw_model();
        if ( time > (_tmp_time + 3.0)){
            for(int i = 0; i != bombs.at(0)._cube_explode_down.size(); i++)
                for (int n = 0; n != players.size(); n++)
                    if (bombs.at(0)._cube_explode_down.at(i).IsCollide(players.at(n))
                    || bombs.at(0)._cube_explode_up.at(i).IsCollide(players.at(n))
                    || bombs.at(0)._cube_explode_right.at(i).IsCollide(players.at(n))
                    || bombs.at(0)._cube_explode_left.at(i).IsCollide(players.at(n)))
                         players.at(n)._life = 0;
            for(int i = 0; i != bombs.at(0)._cube_explode_down.size(); i++)
                for (int n = 0; n != cubes_map.size(); n++)
                    if (bombs.at(0)._cube_explode_down.at(i).IsCollide(cubes_map.at(n))
                    || bombs.at(0)._cube_explode_up.at(i).IsCollide(cubes_map.at(n))
                    || bombs.at(0)._cube_explode_right.at(i).IsCollide(cubes_map.at(n))
                    || bombs.at(0)._cube_explode_left.at(i).IsCollide(cubes_map.at(n))){
                        if (cubes_map.at(n).getName() == "destructible"){
                            cubes_map.at(n).getCollidable_pos().z = 0;
                            cubes_map.at(n).setTexture("Ressources/wood_vert.png");
                            cubes_map.at(n).setName("indestructible");
                        }
                    }
            if(_tmp == 1){
                bombs.at(0).boom_sound();
                _tmp = 2;
            }
            bombs.at(0).end_explode();
            _ia_bomb = false;
        }
    }
    if (_tmp == 2 && time > (_tmp_time + 4.0)) {
            _tmp = 0;
            bombs.at(0).clean_list();
            bombs.clear();
    }
}