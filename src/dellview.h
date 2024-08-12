#pragma once

#include "entity.h"
#include "entity_manager.h"
#include <SFML/Graphics.hpp>

struct ShapeConfig
{
  int   SR; // Shape Radius
  int   CR; // Collision Radius
  int   FR; // Fill Red
  int   FG; // Fill Green
  int   FB; // Fill Blue
  int   OR; // Outline Red
  int   MS; // Max Shapes
  int   OG; // Outline Green
  int   OB; // Outline Blue
  int   OT; // Outline Thickness
  int   V;  // Vertices
  float S;  // Speed
};

enum Status
{
  OK,
  NOT_OK
};

enum ConfigOpt
{
  default_opt,
  shape_opt,
  window_opt
};

class Dellview
{
private:
  sf::RenderWindow m_window;
  EntityManager    m_entities;
  ShapeConfig      m_shape_config;
  int              m_current_frame = 0;
  int              m_running       = true;
  std::string      config;

  Status dv_init();

  // Systems
  void s_input();
  void s_movement();
  void s_render();
  void s_collision();

  // Systems Helpers
  void spawn_shape();

  // Config
  Status    read_config();
  ConfigOpt resolve_config_option(std::string &input);
  void      process_shape_config(std::vector<std::string> &tokens);
  void      process_window_config(std::vector<std::string> &tokens);

public:
  Dellview(const std::string &config);
  Status run();
};
