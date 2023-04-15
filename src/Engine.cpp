#include <cstdlib>
#include <ctime>
#include "Engine.hpp"

[[maybe_unused]] const sf::Time Engine::timePerFrame = sf::seconds(1.f/FPS);

sf::Vector2f Engine::randomiseLocation()
{
  sf::Vector2f ret;
  
  std::srand(std::time(nullptr));
  
  // Generate x and y between 0 and WINDOW_WIDTH or WINDOW_HEIGHT, with a step of SPRITE_SIZE
  do
    ret.x = std::rand() / ((RAND_MAX + 1u) / (WINDOW_WIDTH - SPRITE_SIZE));
  while (int(ret.x) % SPRITE_SIZE);
  do
    ret.y = std::rand() / ((RAND_MAX + 1u) / (WINDOW_HEIGHT - SPRITE_SIZE));
  while (int(ret.y) % SPRITE_SIZE);
  
  // Iterate through snake to avoid generating x and y on snake
  for (const SnakeSection& i: snake)
  {
    if (ret == i.getPosition())
      do
        ret.x = std::rand() / ((RAND_MAX + 1u) / (WINDOW_WIDTH - SPRITE_SIZE));
      while (int(ret.x) % SPRITE_SIZE);
  }
  
  return ret;
}

Engine::Engine()
{
  resolution = sf::Vector2i(WINDOW_WIDTH, WINDOW_HEIGHT);
  window.create(sf::VideoMode(resolution.x, resolution.y), "Snake", sf::Style::Titlebar | sf::Style::Close);
  window.setFramerateLimit(FPS);
  window.setVerticalSyncEnabled(true);

  speed = SNAKE_INITIAL_SPEED;
  snakeDirection = Direction::RIGHT;

  timeSinceLastMove = sf::Time::Zero;

  newSnake();
  appleGenerated = false;
}

void Engine::newSnake()
{
  snake.clear();
  snake.emplace_back(sf::Vector2f(SNAKE_INITIAL_X, SNAKE_INITIAL_Y));
  snake.emplace_back(sf::Vector2f(SNAKE_INITIAL_X - SPRITE_SIZE, SNAKE_INITIAL_Y));
  snake.emplace_back(sf::Vector2f(SNAKE_INITIAL_X - SPRITE_SIZE * 2, SNAKE_INITIAL_Y));
}

void Engine::addSnakeSection()
{
  sf::Vector2f position = snake.back().getPosition();
  snake.emplace_back(position);
}

void Engine::generateApple()
{
  apple.setPosition(randomiseLocation());
  apple.update();
  appleGenerated = true;
}

void Engine::run()
{
  sf::Clock clock;
  sf::Time dt;
  int ret = 0;

  // Main game loop - runs until window is closed
  while (window.isOpen() && !ret)
  {
    dt = clock.restart();
    timeSinceLastMove += dt;

    input();
    ret = update();
    draw();
  }
  
  sf::Event event{};
  
  if (ret == 1)
    while (window.waitEvent(event))
      if (event.type == sf::Event::Closed)
        window.close();
}