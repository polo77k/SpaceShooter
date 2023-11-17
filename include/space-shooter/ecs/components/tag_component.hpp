#pragma once

#include <space-shooter/ecs/component.hpp>

#include <iostream>

namespace space_shooter::ecs {

struct TagComponent : Component {
  std::string tag;

  TagComponent(const std::string& tag);
};

} // namespace space_shooter::ecs