#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <space-shooter/ecs/components/timer_component.hpp>
#include <space-shooter/ecs/components/text_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Font.hpp>

#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

class LevelTimerEntity : public Entity {
public:
  LevelTimerEntity(sf::Time initialTime, const std::filesystem::path &font_path);
  LevelTimerEntity() = delete;

  using Entity::Entity;
};

} // namespace space_shooter::ecs
