#pragma once

#include <space-shooter/ecs/component.hpp>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

#include <filesystem>

namespace space_shooter::ecs {

struct TextComponent : Component {
  std::string text;
  int characterSize;
  sf::Vector2f pos;
  sf::Color color;

  std::filesystem::path font_path;
  bool repeated = false;
  sf::Font font;
  bool loaded = false;

  TextComponent(const std::string& text, const std::filesystem::path &font_path, int characterSize,
                const sf::Vector2f& pos, const sf::Color& color, bool repeated = false);
};

} // namespace space_shooter::ecs