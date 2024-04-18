#include <boost/bind/bind.hpp>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>

using boost::asio::ip::udp;

class IEnemy {
    public:
        virtual ~IEnemy() {}
        virtual void setPositionEnemy(float x, float y) {}
        virtual void setDammageEnemy(int damage) {}
        virtual void setHpEnemy(int hp) {} 
        virtual void setLobbyEnemy(std::string string) {}
        virtual void setEndpointEnemy(udp::endpoint endpoint) {}
        virtual void setMaxPlacementEnemy(std::vector<float> max_placement) {}
        virtual void setMinPlacementEnemy(std::vector<float> min_placement) {}
        virtual void setPosEnemy(std::vector<float> pos) {}
        virtual void setSpeedEnemy(std::vector<float> speed) {}
        virtual void setLeftEnemy(bool left) {}
        virtual void setDownEnemy(bool down) {}
        virtual void setIdEnemy(int id) {}
        virtual void setLifeEnemy(bool life) {}
        virtual bool getLifeEnemy() { return (_life); }
        virtual int getIdEnemy() { return (_id); }
        virtual bool getLeftEnemy() { return (comp); }
        virtual bool getDownEnemy() { return (comp); }
        virtual std::vector<float> getMaxPlacementEnemy() { return (_pos); }
        virtual std::vector<float> getMinPlacementEnemy() { return (_pos); }
        virtual std::vector<float> getPosEnemy() { return (_pos); }
        virtual std::vector<float> getSpeedEnemy() { return (_pos); }
        virtual double getPositionEnemyX() { return (_position); }
        virtual double getPositionEnemyY() { return (_position); }
        virtual int getDamageEnemy() { return (_value); }
        virtual int getHpEnemy() { return (_value); }
        virtual std::string getLobbyEnemy() { return (_name); }
        virtual udp::endpoint getEndpointEnemy() { return (_endpoint); }
    private:
        int _value;
        double _position;
        udp::endpoint _endpoint;
        std::string _name;
        std::vector<float> _pos;
        bool comp;
        bool _life;
        int _id;
};

class EnemyComponent : public IEnemy {
    public:
        EnemyComponent(std::string name);
        ~EnemyComponent();
        void setPositionEnemy(float x, float y);
        void setDammageEnemy(int damage);
        void setHpEnemy(int hp);
        void setLobbyEnemy(std::string name);
        void setEndpointEnemy(udp::endpoint _endpoint);
        void setMaxPlacementEnemy(std::vector<float> max_placement);
        void setMinPlacementEnemy(std::vector<float> min_placement);
        void setPosEnemy(std::vector<float> pos);
        void setSpeedEnemy(std::vector<float> speed);
        void setLeftEnemy(bool left);
        void setDownEnemy(bool down);
        void setIdEnemy(int id);
        void setLifeEnemy(bool life);
        bool getLifeEnemy();
        int getIdEnemy();
        bool getLeftEnemy();
        bool getDownEnemy();
        std::vector<float> getMaxPlacementEnemy();
        std::vector<float> getMinPlacementEnemy();
        std::vector<float> getPosEnemy();
        std::vector<float> getSpeedEnemy();
        double getPositionEnemyX();
        double getPositionEnemyY();
        int getDamageEnemy();
        int getHpEnemy();
        std::string getLobbyEnemy();
        udp::endpoint getEndpointEnemy();
    private:
        float _x;
        float _y;
        int _dmg;
        int _hp;
        bool _left;
        bool _down;
        int _id;
        std::vector<float> _max_placement;
        std::vector<float> _min_placement;
        std::vector<float> _pos;
        std::vector<float> _speed;
        udp::endpoint _endpoint;
        std::string _name;
        bool _life;
};