#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

class BackgroundMusicEntity : public Entity {
public:
  BackgroundMusicEntity(const std::filesystem::path &audio_path);
  BackgroundMusicEntity() = delete;

  using Entity::Entity;
};

} // namespace space_shooter::ecs
