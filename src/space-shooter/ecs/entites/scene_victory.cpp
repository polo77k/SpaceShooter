#include <space-shooter/ecs/entities/scene_victory.hpp>

namespace space_shooter::ecs {

SceneVictory::SceneVictory(const std::string& text, const std::filesystem::path &font_path) {
  add<ClockComponent>(sf::seconds(4.0f));
  add<TagComponent>("Texte");

  sf::Vector2f pos(300.0f, 100.0f);
  sf::Color color(255, 215, 0);
  add<TextComponent>(text, font_path, 75, pos, color);
}

SceneVictory::SceneVictory() {
  add<ClockComponent>(sf::seconds(4.0f));
}


} // namespace space_shooter::ecs
