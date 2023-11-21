#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <SFML/Graphics/Text.hpp>
#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

class SceneVictory : public Entity {
public:
  SceneVictory(const std::string& text, const std::filesystem::path &font_path);
  
  SceneVictory();

  using Entity::Entity;
};

} // namespace space_shooter::ecs
