#pragma once


#include <SFML/Graphics.hpp>
#include "MACROS.hpp"

class Apple
{
private:
    sf::RectangleShape sprite;
    sf::Vector2f position;

public:
    explicit Apple();

    void setPosition(const sf::Vector2f& newPosition);
    sf::RectangleShape getSprite() const;
    
    void update();
};