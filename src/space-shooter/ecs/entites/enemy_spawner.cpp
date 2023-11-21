#include <space-shooter/ecs/entities/enemy_spawner.hpp>

namespace space_shooter::ecs {

EnemySpawnerEntity::EnemySpawnerEntity(sf::Vector2f pos, const std::filesystem::path &texture_path, sf::Vector2f velocity)
{
  add<PositionComponent>(pos.x, pos.y);
  add<TextureComponent>(texture_path);
  add<SpriteComponent>(148, 111, SpriteComponent::Resize::Scale, 0.9f);
  add<TagComponent>("EnemySpawner");
  add<ClockComponent>(sf::seconds(2.0f));
  add<HealthComponent>(3500.0f);
  add<VelocityComponent>(velocity.x, velocity.y);
}

} // namespace space_shooter::ecs
