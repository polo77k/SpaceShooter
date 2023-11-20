#include <space-shooter/ecs/components/sprite_component.hpp>

namespace space_shooter::ecs {
    
    SpriteComponent::SpriteComponent(int width, int height, Resize resize, float size)
      : width{width}, height{height}, resize{resize}, size{size} {}
}