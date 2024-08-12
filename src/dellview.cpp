#include "dellview.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Dellview::Dellview(const std::string &config) : config(config)
{
}

Status Dellview::run()
{
  Status status = this->dv_init();
  if (status)
    return status;

  while (m_running)
  {
    m_entities.update();
    s_movement();
    s_collision();
    s_input();
    s_render();
    m_current_frame++;
  }

  m_window.close();
  return status;
}

Status Dellview::dv_init()
{
  Status status = this->read_config();
  if (status)
    return status;

  spawn_shape();

  return status;
}

void Dellview::s_movement()
{
  // todo
}

void Dellview::s_render()
{
  m_window.clear();
  for (auto e : m_entities.get_entities())
  {
    // todo
  }
  m_window.display();
}

void Dellview::s_collision()
{
  // todo
}

void Dellview::s_input()
{
  sf::Event event;
  while (m_window.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
    {
      m_running = false;
    }
  }
}

void Dellview::spawn_shape()
{
  // todo
}

Status Dellview::read_config()
{
  Status        status = OK;
  std::ifstream infile{this->config};
  if (!infile)
  {
    std::cerr << "Failed to open " << this->config << ".\n";
    return NOT_OK;
  }

  std::string line{};
  while (std::getline(infile, line))
  {
    std::istringstream       ss{line};
    std::string              token{};
    std::vector<std::string> tokens;

    while (std::getline(ss, token, ' '))
    {
      tokens.push_back(token);
    }

    ConfigOpt opt = resolve_config_option(tokens.at(0));
    switch (opt)
    {
      // This is a toy, so no error checking.
      case shape_opt:
        process_shape_config(tokens);
        break;
      case window_opt:
        process_window_config(tokens);
        break;
      case default_opt:
      default:
        std::cerr << "Expected config option not present.\n";
        return NOT_OK;
    }
  }

  return status;
}

void Dellview::process_shape_config(std::vector<std::string> &tokens)
{
  m_shape_config.SR = std::stoi(tokens.at(1));  // Shape Radius
  m_shape_config.CR = std::stoi(tokens.at(2));  // Collision Radius
  m_shape_config.FR = std::stoi(tokens.at(3));  // Fill Red
  m_shape_config.FG = std::stoi(tokens.at(4));  // Fill Green
  m_shape_config.FB = std::stoi(tokens.at(5));  // Fill Blue
  m_shape_config.OR = std::stoi(tokens.at(6));  // Outline Red
  m_shape_config.OG = std::stoi(tokens.at(7));  // Outline Green
  m_shape_config.OB = std::stoi(tokens.at(8));  // Outline Blue
  m_shape_config.OT = std::stoi(tokens.at(9));  // Outline Thickness
  m_shape_config.V  = std::stoi(tokens.at(10)); // Vertices
  m_shape_config.MS = std::stoi(tokens.at(11)); // Max Shapes
  m_shape_config.S  = std::stof(tokens.at(12)); // Speed
}

void Dellview::process_window_config(std::vector<std::string> &tokens)
{
  int width     = std::stoi(tokens.at(1));
  int height    = std::stoi(tokens.at(2));
  int framerate = std::stoi(tokens.at(3));

  m_window.create(sf::VideoMode(width, height), "dellview");
  m_window.setFramerateLimit(framerate);
}

ConfigOpt Dellview::resolve_config_option(std::string &input)
{
  // clang-format off
  const std::map<std::string, ConfigOpt> options{
    {"Shape", shape_opt},
    {"Window", window_opt}
  };
  // clang-format on

  ConfigOpt opt{default_opt};

  auto it = options.find(input);
  if (it == options.end())
    return opt;

  opt = it->second;
  return opt;
}
