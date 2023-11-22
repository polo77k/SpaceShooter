#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/components/text_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>

#include <SFML/Graphics/Text.hpp>

#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

class SceneRules : public Entity {
public:
  SceneRules(const std::string& text, const std::filesystem::path &font_path);

  SceneRules() = delete;

  using Entity::Entity;
};

} // namespace space_shooter::ecs
