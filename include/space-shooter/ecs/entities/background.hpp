#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/components/texture_component.hpp>

#include <filesystem>

#include <memory>

namespace space_shooter::ecs {

class BackgroundEntity : public Entity {
public:
  BackgroundEntity(const std::filesystem::path &texture_path, int window_width,
                   int window_height);
  BackgroundEntity() = delete;

  using Entity::Entity;
};

} // namespace space_shooter::ecs
