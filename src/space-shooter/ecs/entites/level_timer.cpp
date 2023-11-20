#include <space-shooter/ecs/entities/level_timer.hpp>

#include <space-shooter/ecs/components/timer_component.hpp>
#include <space-shooter/ecs/components/text_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

namespace space_shooter::ecs {

LevelTimerEntity::LevelTimerEntity(sf::Time initialTime, const std::filesystem::path &font_path)
{
  add<TagComponent>("Timer");
  add<TimerComponent>(initialTime);

  sf::Vector2f pos(0.0f, 25.0f);
  sf::Color color(255, 0, 0);
  add<TextComponent>(" ", font_path, 20, pos, color);
}

} // namespace space_shooter::ecs
