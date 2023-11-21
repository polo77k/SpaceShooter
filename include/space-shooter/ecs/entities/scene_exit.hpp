#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <space-shooter/ecs/components/clock_component.hpp>
#include <space-shooter/ecs/components/text_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Time.hpp>

#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

class SceneExit : public Entity {
public:
  SceneExit(const std::string& text, const std::filesystem::path &font_path);
  
  SceneExit();

  using Entity::Entity;
};

} // namespace space_shooter::ecs
