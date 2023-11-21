#include <space-shooter/ecs/entities/enemy_missile.hpp>

namespace space_shooter::ecs {

EnemyMissileEntity::EnemyMissileEntity(sf::Vector2f pos, const std::filesystem::path &texture_path, sf::Vector2f velocity)
{
  add<PositionComponent>(pos.x, pos.y);
  add<InputComponent>();
  add<TextureComponent>(texture_path);
  add<SpriteComponent>(52, 88, SpriteComponent::Resize::Scale, 0.3f);
  add<VelocityComponent>(velocity.x, velocity.y);
  add<TagComponent>("EnemyMissile");
  add<DamageComponent>(100.0f);
}

} // namespace space_shooter::ecs
