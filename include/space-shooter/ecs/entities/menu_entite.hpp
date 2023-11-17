#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

class MenuEntity : public Entity {
public:
  MenuEntity();

  using Entity::Entity;
};

} // namespace space_shooter::ecs
