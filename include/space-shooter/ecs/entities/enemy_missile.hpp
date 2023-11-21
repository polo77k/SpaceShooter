#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/components/texture_component.hpp>
#include <space-shooter/ecs/components/velocity_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/damage_component.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

class EnemyMissileEntity : public Entity {
public:
  EnemyMissileEntity(sf::Vector2f pos, const std::filesystem::path &texture_path, sf::Vector2f velocity);
  
  EnemyMissileEntity() = delete;

  using Entity::Entity;
};

} // namespace space_shooter::ecs
