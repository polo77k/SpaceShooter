#include <space-shooter/ecs/systems/enemy_spawner_system.hpp>

#include <space-shooter/ecs/entities/enemy_ship.hpp>
#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/clock_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

EnemySpawnerSystem::EnemySpawnerSystem()
    : System{
          type_list<PositionComponent, TagComponent, ClockComponent>{}} {}

void EnemySpawnerSystem::update(const sf::Time &delta_time,
                            std::vector<Entity *> &entities, Manager &manager) {

  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    auto &pos = e->get<PositionComponent>();
    const auto &tag = e->get<TagComponent>();
    auto &timer = e->get<ClockComponent>();
    
    // Tag EnemySpawner
    if(tag.tag == "EnemySpawner")
    {
      if(timer.timer >= timer.cooldown_timer)
        {
          // random position
          auto x1 = manager.gameState().width - 100.0f;
          auto x = random(50, x1);
          
          // new EnemyShip
          sf::Vector2f initialPosition(x, pos.y);
          sf::Vector2f initialVelocite(150.0f, 150.0f);
          auto imagePath = manager.gameState().config.path_to_textures / "EnemyShip.png";
          manager.registerEntity<space_shooter::ecs::EnemyShipEntity>(initialPosition, imagePath, initialVelocite);

          // reset cooldown
          timer.timer = 0.0f;
        }
    }

  }
}

} // namespace space_shooter::ecs
