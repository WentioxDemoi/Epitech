#include "../../Components/Enemy/Enemy.hpp"
#include <boost/bind/bind.hpp>
#include <boost/asio.hpp>
#include <boost/array.hpp>

using boost::asio::ip::udp;

class EnemyEntity {
    public:
        EnemyEntity();
        ~EnemyEntity();
        void createEnemy(std::string name, float x, float y, int dammage, int hp, std::string nameLobby, udp::endpoint endpoint);
        void AddEnemyComponent(std::string _name);
        void setDammageEnemyComponent(int damage);
        void setHpEnemyComponent(int hp);
        void setLobbyEnemyComponent(std::string string);
        void setEndpointEnemyComponent(udp::endpoint endpoint);
        void setIdEnemyComponent(int id);
        void setLifeEnemyComponent(bool life);
        bool getLifeEnemyComponent();
        int getIdEnemyComponent();
        void setMaxPlacementEnemyComponent(std::vector<float> max_placement);
        void setMinPlacementEnemyComponent(std::vector<float> min_placement);
        void setPosEnemyComponent(std::vector<float> pos);
        void setSpeedEnemyComponent(std::vector<float> speed);

        void setLeftEnemyComponent(bool left);
        void setDownEnemyComponent(bool down);

        bool getLeftEnemyComponent();
        bool getDownEnemyComponent();

        std::vector<float> getMaxPlacementEnemyComponent();
        std::vector<float> getMinPlacementEnemyComponent();
        std::vector<float> getPosEnemyComponent();
        std::vector<float> getSpeedEnemyComponent();

        double getEnemyXComponent();
        double getPositionEnemyYComponent();
        int getDamageEnemyComponent();
        int getHpEnemyComponent();
        std::string getLobbyEnemyComponent();
    private:
        std::vector<std::shared_ptr<IEnemy> > m_components;
};