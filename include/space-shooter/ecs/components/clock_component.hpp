#pragma once

#include <space-shooter/ecs/component.hpp>

namespace space_shooter::ecs {

struct ClockComponent : Component {
  float timer = 0.0f;
  float cooldown_timer = 1.0f;

  ClockComponent() = default;
  ClockComponent(float cooldown);
};

} // namespace space_shooter::ecs