#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <SFML/Graphics/Text.hpp>
#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

class SceneExit : public Entity {
public:
  SceneExit(const sf::Font& font, const std::string& texte);
  
  SceneExit();

  using Entity::Entity;
};

} // namespace space_shooter::ecs
