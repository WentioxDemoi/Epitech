#include "../../Components/Fire/Fire.hpp"
#include <vector>
#include <boost/bind/bind.hpp>
#include <boost/asio.hpp>
#include <boost/array.hpp>

using boost::asio::ip::udp;

class FireEntity {
    public:
        FireEntity();
        ~FireEntity();
        void AddFireComponent(udp::endpoint _endpoint);
        void setPositionFireComponent(float x, float y);
        void setIdFireComponent(int id);
        float getPositionFireXComponent();
        float getPositionFireYComponent();
        udp::endpoint getEndpointFireComponent();
        int getIdFireComponent();
    private:
        std::vector<std::shared_ptr<IFire> > m_components;
};