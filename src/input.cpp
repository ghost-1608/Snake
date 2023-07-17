#include "Engine.hpp"

bool opposite(const Engine::Direction& d1, const Engine::Direction& d2)
{
  if (d1 == Engine::Direction::UP && d2 == Engine::Direction::DOWN)
    return true;
  if (d1 == Engine::Direction::DOWN && d2 == Engine::Direction::UP)
    return true;
  if (d1 == Engine::Direction::LEFT && d2 == Engine::Direction::RIGHT)
    return true;
  if (d1 == Engine::Direction::RIGHT && d2 == Engine::Direction::LEFT)
    return true;

  return false;
}

void Engine::addDirection(const Direction newDirection)
{
  if (directionQueue.empty())
  {
    if (opposite(snakeDirection, newDirection))
      return;
    directionQueue.emplace_back(newDirection);
    return;
  }
  
  if (newDirection == directionQueue.back() || opposite(newDirection, directionQueue.back()))
    return;

  directionQueue.emplace_back(newDirection);
}

void Engine::input()
{
  sf::Event event{};

  while (window.pollEvent(event))
  {
    switch (event.type)
    {
      // Window closed
      case sf::Event::Closed:
        window.close();
        break;
      // Key event
      case sf::Event::KeyPressed:
        switch (event.key.code)
        {
          case sf::Keyboard::Up:
          case sf::Keyboard::W:
              addDirection(Direction::UP);
              break;
          case sf::Keyboard::Left:
          case sf::Keyboard::A:
              addDirection(Direction::LEFT);
              break;
          case sf::Keyboard::Down:
          case sf::Keyboard::S:
              addDirection(Direction::DOWN);
              break;
          case sf::Keyboard::Right:
          case sf::Keyboard::D:
              addDirection(Direction::RIGHT);
              break;
          default:;
        }
        break;
      default:;
    }
  }
}