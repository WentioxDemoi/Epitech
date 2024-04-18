#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <vector>
#include <memory>
#include <typeinfo>
#include <typeindex>
#include <exception>
#include <iostream>

class Entity
{
public:
    Entity() = default;
    ~Entity() {this->components.clear();}

    template <typename T, typename... Args>
    T &set(Args &&...args)
    {
        components[typeid(T)] = std::make_shared<T>(std::forward<Args>(args)...);
        return get<T>();
    }

    template <typename T>
    bool has()
    {
        return components.find(typeid(T)) != components.end();
    }

    template <typename T>
    T &get()
    {
        if (has<T>())
            return *std::static_pointer_cast<T>(components[typeid(T)]).get();
        else
            throw;
    }

    template <typename T>
    void remove()
    {
        components.erase(typeid(T));
    }
private:
    std::map<std::type_index, std::shared_ptr<void>> components;
};