#include <space-shooter/ecs/entities/player_ship_health_bar.hpp>

#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/components/texture_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

namespace space_shooter::ecs {

PlayerShipHealthBarEntity::PlayerShipHealthBarEntity(sf::Vector2f pos, const std::filesystem::path &texture_path)
{
  add<PositionComponent>(pos.x, pos.y);
  add<TextureComponent>(texture_path);
  add<SpriteComponent>(1800, 155, SpriteComponent::Resize::Scale, 0.5f);
  add<TagComponent>("PlayerShipHealthBar");
}

} // namespace space_shooter::ecs
