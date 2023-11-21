#include <space-shooter/ecs/entities/enemy_spawner.hpp>

#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/components/texture_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/clock_component.hpp>
#include <space-shooter/ecs/components/health_component.hpp>
#include <space-shooter/ecs/components/velocity_component.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

namespace space_shooter::ecs {

EnemySpawnerEntity::EnemySpawnerEntity(sf::Vector2f pos, const std::filesystem::path &texture_path, sf::Vector2f velocity)
{
  add<PositionComponent>(pos.x, pos.y);
  add<TextureComponent>(texture_path);
  add<SpriteComponent>(148, 111, SpriteComponent::Resize::Scale, 0.9f);
  add<TagComponent>("EnemySpawner");
  add<ClockComponent>(sf::seconds(2.5f));
  add<HealthComponent>(2500.0f);
  add<VelocityComponent>(velocity.x, velocity.y);
}

} // namespace space_shooter::ecs
