#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <space-shooter/ecs/components/music_component.hpp>

#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

class BackgroundMusicEntity : public Entity {
public:
  BackgroundMusicEntity(const std::filesystem::path &audio_path, const float volume);
  BackgroundMusicEntity() = delete;

  using Entity::Entity;
};

} // namespace space_shooter::ecs
