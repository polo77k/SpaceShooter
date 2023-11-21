#include <space-shooter/ecs/entities/player_ship.hpp>

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
