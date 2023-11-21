#include <space-shooter/ecs/entities/player_ship.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/components/texture_component.hpp>
#include <space-shooter/ecs/components/velocity_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/clock_component.hpp>
#include <space-shooter/ecs/components/health_component.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

namespace space_shooter::ecs {

PlayerShipEntity::PlayerShipEntity(sf::Vector2f pos, const std::filesystem::path &texture_path, sf::Vector2f velocity)
{
  add<PositionComponent>(pos.x, pos.y);
  add<InputComponent>();
  add<TextureComponent>(texture_path);
  add<SpriteComponent>(720, 713, SpriteComponent::Resize::Scale, 0.12f);
  add<VelocityComponent>(velocity.x, velocity.y);
  add<TagComponent>("PlayerShip");
  add<ClockComponent>(sf::seconds(0.2f));
  add<HealthComponent>(1000.0f);
}

} // namespace space_shooter::ecs
