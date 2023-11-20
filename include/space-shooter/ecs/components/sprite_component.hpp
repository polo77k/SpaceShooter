#pragma once

#include <space-shooter/ecs/component.hpp>

namespace space_shooter::ecs {

struct SpriteComponent : Component {
  enum class Resize { Crop, Scale };

  int width = 0;
  int height = 0;
  Resize resize = Resize::Crop;
  float size = 1.0f; // size by default

  SpriteComponent() = default;
  SpriteComponent(int width, int height, Resize resize = Resize::Crop, float size = 1.0f);
};

} // namespace space_shooter::ecs