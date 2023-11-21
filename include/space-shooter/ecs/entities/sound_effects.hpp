#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

class SoundEffetsEntity : public Entity {
public:
  SoundEffetsEntity(const std::filesystem::path &audio_path, const float volume);
  
  SoundEffetsEntity() = delete;

  using Entity::Entity;
};

} // namespace space_shooter::ecs
