#include <space-shooter/ecs/entities/enemy_missile.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/components/texture_component.hpp>
#include <space-shooter/ecs/components/velocity_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/damage_component.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

namespace space_shooter::ecs {

EnemyMissileEntity::EnemyMissileEntity(sf::Vector2f pos, const std::filesystem::path &texture_path, sf::Vector2f velocity)
{
  add<PositionComponent>(pos.x, pos.y);
  add<InputComponent>();
  add<TextureComponent>(texture_path);
  add<SpriteComponent>(124, 141, SpriteComponent::Resize::Scale, 0.3f);
  add<VelocityComponent>(velocity.x, velocity.y);
  add<TagComponent>("EnemyMissile");
  add<DamageComponent>(50.0f);
}

} // namespace space_shooter::ecs