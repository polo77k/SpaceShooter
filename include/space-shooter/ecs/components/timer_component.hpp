#pragma once

#include <space-shooter/ecs/component.hpp>

#include <SFML/System/Time.hpp>

namespace space_shooter::ecs {

struct TimerComponent : Component {
  sf::Time time;

  TimerComponent() = delete;
  TimerComponent(sf::Time time);
};

} // namespace space_shooter::ecs