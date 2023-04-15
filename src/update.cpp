#include "Engine.hpp"
#include <iostream>

int Engine::update()
{
  if (timeSinceLastMove < sf::seconds(1.f / float(speed)))
    return 0;
  
  if (!appleGenerated)
    generateApple();
  
  sf::Vector2f oldHeadSectionPosition;
  
  if (!directionQueue.empty())
  {
    snakeDirection = directionQueue.front();
    directionQueue.pop_front();
  }
  
  oldHeadSectionPosition = snake.front().getPosition();
  
  // Make the old tail the new head (Constant complexity algorithm to update position)
  snake.push_front(snake.back());
  snake.pop_back();
  
  // Update the new head positions
  switch (snakeDirection)
  {
    case Direction::RIGHT:
      snake.front().setPosition(sf::Vector2f(oldHeadSectionPosition.x + float(SPRITE_SIZE), oldHeadSectionPosition.y));
      break;
    case Direction::LEFT:
      snake.front().setPosition(sf::Vector2f(oldHeadSectionPosition.x - float(SPRITE_SIZE), oldHeadSectionPosition.y));
      break;
    case Direction::DOWN:
      snake.front().setPosition(sf::Vector2f(oldHeadSectionPosition.x, oldHeadSectionPosition.y + float(SPRITE_SIZE)));
      break;
    case Direction::UP:
      snake.front().setPosition(sf::Vector2f(oldHeadSectionPosition.x, oldHeadSectionPosition.y - float(SPRITE_SIZE)));
      break;
  }
  
  if (!sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f(resolution)).contains(snake.front().getPosition()))
    return 1;
  
  std::cout << '{';
  for (auto& i: snake)
    std::cout << '(' << i.getPosition().x << ", " << i.getPosition().y << ')' << ' ';
  std::cout << "}\n";
  
  for (std::list<SnakeSection>::iterator i = ++snake.begin(); i != snake.end(); i++)
    if (snake.front().getSprite().getGlobalBounds().intersects(i->getSprite().getGlobalBounds()))
      return 1;
  
  // Update the snake sections
  for (SnakeSection& i: snake)
    i.update();
  
  if (apple.getSprite().getGlobalBounds().intersects(snake.front().getSprite().getGlobalBounds()))
  {
    appleGenerated = false;
    addSnakeSection();
    speed += SNAKE_INCREMENT_SPEED;
  }
 
  timeSinceLastMove = sf::Time::Zero;
  
  return 0;
}