#include <space-shooter/ecs/entities/scene_menu.hpp>

namespace space_shooter::ecs {

SceneMenu::SceneMenu(const std::string& text, const std::filesystem::path &font_path) {
  add<InputComponent>();
  add<TextBlinkComponent>();

  sf::Vector2f pos(50.0f, 200.0f);
  sf::Color color(255, 0, 25);
  add<TextComponent>(text, font_path, 45, pos, color);
}

SceneMenu::SceneMenu() {
  add<InputComponent>();
}


} // namespace space_shooter::ecs
