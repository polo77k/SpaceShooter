#include <space-shooter/ecs/entities/scene_exit.hpp>

#include <filesystem>

namespace space_shooter::ecs {

SceneExit::SceneExit(const std::string& text, const std::filesystem::path &font_path) {
  add<ClockComponent>(sf::seconds(4.0f));
  add<TagComponent>("Texte");

  sf::Vector2f pos(100.0f, 700.0f);
  sf::Color color(255, 0, 55);
  add<TextComponent>(text, font_path, 45, pos, color);
}

SceneExit::SceneExit() {
  add<ClockComponent>(sf::seconds(4.0f));
}


} // namespace space_shooter::ecs
