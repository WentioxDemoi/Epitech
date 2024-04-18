#include "Fire.hpp"

FireComponent::FireComponent(udp::endpoint endpoint)
{
    _endpoint = endpoint;
}

FireComponent::~FireComponent()
{

}

void FireComponent::setPositionFire(float x, float y)
{
    _x = x;
    _y = y;
}

void FireComponent::setIdFire(int id)
{
    _id = id;
}

float FireComponent::getPositionFireX()
{
    return (_x);
}

float FireComponent::getPositionFireY()
{
    return (_y);
}

udp::endpoint FireComponent::getEndpointFire()
{
    return (_endpoint);
}

int FireComponent::getIdFire()
{
    return (_id);
}