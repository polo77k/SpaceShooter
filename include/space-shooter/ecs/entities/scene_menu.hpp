#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <SFML/Graphics/Text.hpp>
#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

class SceneMenu : public Entity {
public:
  SceneMenu(const sf::Font& font, const std::string& texte);
  
  SceneMenu();

  using Entity::Entity;
};

} // namespace space_shooter::ecs
