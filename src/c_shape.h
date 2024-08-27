#pragma once

#include <SFML/Graphics.hpp>

struct CShape
{
  sf::CircleShape circle;

  CShape(float radius, int points, sf::Color &fill, sf::Color &outline, float thickness)
      : circle(radius, points)
  {
    circle.setFillColor(fill);
    circle.setOutlineColor(outline);
    circle.setOutlineThickness(thickness);
    circle.setOrigin(radius, radius);
  }
};

// todo rect shape
