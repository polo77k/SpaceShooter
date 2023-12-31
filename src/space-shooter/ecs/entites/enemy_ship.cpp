#include <space-shooter/ecs/entities/enemy_ship.hpp>

namespace space_shooter::ecs {

EnemyShipEntity::EnemyShipEntity(sf::Vector2f pos, const std::filesystem::path &texture_path, sf::Vector2f velocity)
{
  add<PositionComponent>(pos.x, pos.y);
  add<InputComponent>();
  add<TextureComponent>(texture_path);
  add<SpriteComponent>(149, 115, SpriteComponent::Resize::Scale, 0.5f);
  add<VelocityComponent>(velocity.x, velocity.y);
  add<TagComponent>("EnemyShip");
  add<ClockComponent>(sf::seconds(1.5f));
  add<HealthComponent>(200.0f);
}

} // namespace space_shooter::ecs
