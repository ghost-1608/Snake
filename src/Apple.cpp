#include "Apple.hpp"

Apple::Apple()
{
  sprite.setSize(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
  sprite.setOutlineThickness(-1);
  sprite.setFillColor(sf::Color::Red);
  sprite.setOutlineColor(sf::Color::Black);
}

void Apple::setPosition(const sf::Vector2f& newPosition)
{
  position = newPosition;
}

sf::RectangleShape Apple::getSprite() const
{
  return sprite;
}

void Apple::update()
{
  sprite.setPosition(position);
}