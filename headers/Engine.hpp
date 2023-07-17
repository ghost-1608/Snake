#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <list>
#include <deque>
#include "MACROS.hpp"
#include "SnakeSection.hpp"
#include "Apple.hpp"

class Engine
{
public:
  enum Direction { UP, DOWN, LEFT, RIGHT };

private:
  // Window
  sf::Vector2i resolution;
  sf::RenderWindow window;
  [[maybe_unused]] static const sf::Time timePerFrame;
  
  std::list<SnakeSection> snake;
  Direction snakeDirection;
  int speed;
  std::deque<Direction> directionQueue;
  
  Apple apple;
  bool appleGenerated;
  
  sf::Time timeSinceLastMove;
  
  sf::Vector2f randomiseLocation();

public:
  Engine();
  
  void newSnake();
  void addSnakeSection();
  void addDirection(const Direction newDirection);
  
  void generateApple();
  
  void draw();
  void input();
  int update();
  
  // Main loop
  void run();
};