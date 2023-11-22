#include <space-shooter/ecs/entities/scene_rules.hpp>

namespace space_shooter::ecs {

SceneRules::SceneRules(const std::string& text, const std::filesystem::path &font_path) {
  add<TagComponent>("Texte");
  add<InputComponent>();

  sf::Vector2f pos(50.0f, 50.0f);
  sf::Color color(255, 0, 0);
  add<TextComponent>(text, font_path, 45, pos, color);
}

} // namespace space_shooter::ecs
