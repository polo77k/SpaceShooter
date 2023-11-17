#pragma once

#include <space-shooter/ecs/component.hpp>

#include <SFML/Graphics/Text.hpp>

namespace space_shooter::ecs {

struct TextBlinkComponent : Component {

  sf::Text text;
  bool isVisible = true;
  float blinkTime = 0.5f; // fréquence de clignotement

  TextBlinkComponent(const sf::Font& font, const std::string& texte);

};

} // namespace space_shooter::ecs
