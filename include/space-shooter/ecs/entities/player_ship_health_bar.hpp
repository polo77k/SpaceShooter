#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

class PlayerShipHealthBarEntity : public Entity {
public:
  PlayerShipHealthBarEntity(sf::Vector2f pos, const std::filesystem::path &texture_path);
  
  PlayerShipHealthBarEntity() = delete;

  using Entity::Entity;
};

} // namespace space_shooter::ecs
