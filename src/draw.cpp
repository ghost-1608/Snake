#include "Engine.hpp"

void Engine::draw()
{
  window.clear(sf::Color::Black);
  
  if (appleGenerated)
    window.draw(apple.getSprite());
  
  for (SnakeSection& i: snake)
    window.draw(i.getSprite());

  window.display();
}