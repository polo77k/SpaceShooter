#pragma once

#include <space-shooter/ecs/component.hpp>

#include <SFML/System/Time.hpp>

namespace space_shooter::ecs {

struct ClockComponent : Component {
  sf::Time clock = sf::Time::Zero;
  sf::Time cooldown;

  ClockComponent() = default;
  ClockComponent(sf::Time cooldown);
};

} // namespace space_shooter::ecs