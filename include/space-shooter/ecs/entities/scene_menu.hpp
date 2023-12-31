#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/components/text_component.hpp>
#include <space-shooter/ecs/components/text_blink_component.hpp>

#include <SFML/Graphics/Text.hpp>
#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

class SceneMenu : public Entity {
public:
  SceneMenu(const std::string& text, const std::filesystem::path &font_path);
  
  SceneMenu();

  using Entity::Entity;
};

} // namespace space_shooter::ecs
