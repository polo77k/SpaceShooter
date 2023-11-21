#include <space-shooter/ecs/systems/movement_spawner_system.hpp>

#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/velocity_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

MovementSpawnerSystem::MovementSpawnerSystem()
    : System{
          type_list<VelocityComponent, PositionComponent, SpriteComponent, TagComponent>{}} {}

void MovementSpawnerSystem::update(const sf::Time &delta_time,
                            std::vector<Entity *> &entities, Manager &manager) {

  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    auto &vel = e->get<VelocityComponent>();
    auto &pos = e->get<PositionComponent>();
    const auto &sprite = e->get<SpriteComponent>();
    const auto &tag = e->get<TagComponent>();

    // Tag EnemySpawner
    if(tag.tag == "EnemySpawner")
    {
      // Switch direction
      if(pos.x <= 100)
      {
        vel.vx = -vel.vx; 
      }
      if(pos.x >= 700)
      {
        vel.vx = -vel.vx;
      }

      // Direction
      if(vel.vx <= 0.0f)
      {
        if(pos.x + vel.vx * delta_time.asSeconds() > 0)
        {
          pos.x += vel.vx * delta_time.asSeconds();
        }
      }
      else
      {
        if(pos.x + vel.vx * delta_time.asSeconds() + sprite.width*sprite.size < manager.gameState().width)
        {
          pos.x += vel.vx * delta_time.asSeconds();
        }
      }
    }

  }
}

} // namespace space_shooter::ecs
