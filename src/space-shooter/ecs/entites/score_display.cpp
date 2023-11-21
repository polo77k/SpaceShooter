#include <space-shooter/ecs/entities/score_display.hpp>

namespace space_shooter::ecs {

ScoreDisplayEntity::ScoreDisplayEntity(const std::filesystem::path &font_path)
{
  add<TagComponent>("Score");
  add<ScoreComponent>();

  sf::Vector2f pos(0.0f, 45.0f);
  sf::Color color(255, 0, 0);
  add<TextComponent>(" ", font_path, 20, pos, color);
}

} // namespace space_shooter::ecs
