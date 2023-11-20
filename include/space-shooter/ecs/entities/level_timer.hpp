#pragma once

#include <space-shooter/ecs/entity.hpp>

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
