#pragma once

#include <space-shooter/ecs/component.hpp>

#include <SFML/System/Time.hpp>

namespace space_shooter::ecs {

struct TextBlinkComponent : Component {

  bool isVisible = true;
  sf::Time blinkTime = sf::seconds(0.5f); // fréquence de clignotement

  TextBlinkComponent() = default;
  TextBlinkComponent(sf::Time blinkTime);
};

} // namespace space_shooter::ecs
