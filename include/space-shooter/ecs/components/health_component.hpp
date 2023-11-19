#pragma once

#include <space-shooter/ecs/component.hpp>

namespace space_shooter::ecs {

struct HealthComponent : Component {
  float health = 0.f;
  float max_health = 0.f;

  HealthComponent() = default;
  HealthComponent(float health);
};

} // namespace space_shooter::ecs