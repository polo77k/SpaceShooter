#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <SFML/Graphics/Text.hpp>
#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

class MenuEntity : public Entity {
public:
  MenuEntity(const sf::Font& font, const std::string& texte);
  
  MenuEntity();

  using Entity::Entity;
};

} // namespace space_shooter::ecs
