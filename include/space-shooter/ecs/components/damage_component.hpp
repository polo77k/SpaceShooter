#pragma once

#include <space-shooter/ecs/component.hpp>

namespace space_shooter::ecs {

struct DamageComponent : Component {
  float damage = 0.f;

  DamageComponent() = default;
  DamageComponent(float damage);
};

} // namespace space_shooter::ecs