#include <iostream>
#include <vector>
#include <boost/bind/bind.hpp>
#include <boost/asio.hpp>
#include <boost/array.hpp>

using boost::asio::ip::udp;

class IFire {
    public:
        virtual ~IFire() {}
        virtual void setPositionFire(float x, float y) {}
        virtual void setIdFire(int id) {}
        virtual float getPositionFireX() { return (_pos); }
        virtual float getPositionFireY() { return (_pos); }
        virtual udp::endpoint getEndpointFire() { return (_endpoint); }
        virtual int getIdFire() { return (_id); }
    private:
        udp::endpoint _endpoint;
        float _pos;
        int _id;
};

class FireComponent : public IFire {
    public:
        FireComponent(udp::endpoint endpoint);
        ~FireComponent();
        void setPositionFire(float x, float y);
        void setIdFire(int id);
        float getPositionFireX();
        float getPositionFireY();
        udp::endpoint getEndpointFire();
        int getIdFire();
    private:
        udp::endpoint _endpoint;
        float _x;
        float _y;
        int _id;
};
