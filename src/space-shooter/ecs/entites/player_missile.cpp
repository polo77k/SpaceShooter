#include <space-shooter/ecs/entities/player_missile.hpp>

namespace space_shooter::ecs {

PlayerMissileEntity::PlayerMissileEntity(sf::Vector2f pos, const std::filesystem::path &texture_path, sf::Vector2f velocity)
{
  add<PositionComponent>(pos.x, pos.y);
  add<InputComponent>();
  add<TextureComponent>(texture_path);
  add<SpriteComponent>(30, 63, SpriteComponent::Resize::Scale, 0.5f);
  add<VelocityComponent>(velocity.x, velocity.y);
  add<TagComponent>("PlayerMissile");
  add<DamageComponent>(50.0f);
}

} // namespace space_shooter::ecs
