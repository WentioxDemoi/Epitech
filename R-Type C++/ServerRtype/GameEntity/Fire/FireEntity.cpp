#include "FireEntity.hpp"

FireEntity::FireEntity()
{

}

FireEntity::~FireEntity()
{

}

void FireEntity::AddFireComponent(udp::endpoint _endpoint)
{
    std::shared_ptr<FireComponent> _fire = std::make_shared<FireComponent>(_endpoint);
    m_components.push_back(_fire);
}

void FireEntity::setPositionFireComponent(float x, float y)
{
    m_components[0]->setPositionFire(x, y);
}

void FireEntity::setIdFireComponent(int id)
{
    m_components[0]->setIdFire(id);
}

float FireEntity::getPositionFireXComponent()
{
    return (m_components[0]->getPositionFireX());
}

float FireEntity::getPositionFireYComponent()
{
    return (m_components[0]->getPositionFireY());
}

udp::endpoint FireEntity::getEndpointFireComponent()
{
    return (m_components[0]->getEndpointFire());
}

int FireEntity::getIdFireComponent()
{
    return (m_components[0]->getIdFire());
}