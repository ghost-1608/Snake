#pragma once


#include <SFML/Graphics.hpp>
#include "MACROS.hpp"

class SnakeSection
{
private:
    sf::Vector2f position;
    sf::RectangleShape sprite;

public:
    explicit SnakeSection(const sf::Vector2f& startPosition);

    sf::Vector2f getPosition() const;

    void setPosition(const sf::Vector2f& newPosition);

    sf::RectangleShape getSprite() const;

    void update();
};