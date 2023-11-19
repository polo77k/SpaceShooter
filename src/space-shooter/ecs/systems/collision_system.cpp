#include <space-shooter/ecs/systems/collision_system.hpp>

#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/health_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/components/damage_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

CollisionSystem::CollisionSystem()
    : System{
          type_list<PositionComponent, TagComponent, SpriteComponent>{}} {}

void CollisionSystem::update(const sf::Time &delta_time,
                            std::vector<Entity *> &entities, Manager &manager) {

  for (auto e1 : entities) {
    assert(hasRequiredComponents(*e1));

    const auto &pos1 = e1->get<PositionComponent>();
    const auto &tag1 = e1->get<TagComponent>();
    const auto &sprite1 = e1->get<SpriteComponent>();

    // Tag PlayerShip || EnemyShip
    if(tag1.tag == "PlayerShip" || tag1.tag == "EnemyShip")
    {
        auto &health = e1->get<HealthComponent>();

        for (auto e2 : entities)
        {
            assert(hasRequiredComponents(*e2));

            const auto &pos2 = e2->get<PositionComponent>();
            const auto &tag2 = e2->get<TagComponent>();
            auto &damage = e2->get<DamageComponent>();
            const auto &sprite2 = e2->get<SpriteComponent>();

            // Tag PlayerMissile || EnemyMissile
            if(tag1.tag == "PlayerShip" && tag2.tag == "EnemyMissile"
            || tag1.tag == "EnemyShip" && tag2.tag == "PlayerMissile")
            {   
                // Collision AABB
                if(pos1.x < pos2.x + sprite2.width*sprite2.size && pos1.x + sprite1.width*sprite1.size > pos2.x &&
                pos1.y < pos2.y + sprite2.height*sprite2.size && pos1.y + sprite1.height*sprite1.size > pos2.y)
                {
                    // Damage
                    health.health -= damage.damage;

                    // Kill Missile
                    e2->kill();
                }
            }
        }
    }
  }
}

} // namespace space_shooter::ecs
