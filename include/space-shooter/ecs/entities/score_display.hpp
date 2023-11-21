#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <space-shooter/ecs/components/score_component.hpp>
#include <space-shooter/ecs/components/text_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

class ScoreDisplayEntity : public Entity {
public:
  ScoreDisplayEntity(const std::filesystem::path &font_path);
  
  ScoreDisplayEntity() = delete;

  using Entity::Entity;
};

} // namespace space_shooter::ecs
