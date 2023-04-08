#include "SnakeSection.hpp"

SnakeSection::SnakeSection(const sf::Vector2f& startPosition)
{
  sprite.setSize(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
  sprite.setOutlineThickness(-1);
  sprite.setFillColor(sf::Color::Green);
  sprite.setOutlineColor(sf::Color::Black);
  sprite.setPosition(startPosition);
  
  position = startPosition;
}

sf::Vector2f SnakeSection::getPosition() const
{
  return position;
}

void SnakeSection::setPosition(const sf::Vector2f &newPosition)
{
  position = newPosition;
}

sf::RectangleShape SnakeSection::getSprite() const
{
  return sprite;
}

void SnakeSection::update()
{
  sprite.setPosition(position);
}
