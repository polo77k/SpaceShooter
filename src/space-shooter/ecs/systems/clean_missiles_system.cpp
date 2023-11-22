#include <space-shooter/ecs/systems/clean_missiles_system.hpp>

#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

CleanMissilesSystem::CleanMissilesSystem()
    : System{
          type_list<TagComponent, PositionComponent>{}} {}

void CleanMissilesSystem::update(const sf::Time &delta_time,
                            std::vector<Entity *> &entities, Manager &manager) {

  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    const auto &tag = e->get<TagComponent>();
    const auto &pos = e->get<PositionComponent>();

    // Tag PlayerMissile
    if(tag.tag == "PlayerMissile")
    {
      // Kill PlayerMissile
      if(pos.y < -25.0f)
      {
        e->kill();
      }
    }

    // Tag EnemyMissile
    if(tag.tag == "EnemyMissile")
    {
      // Kill EnemyMissile
      if(pos.y > manager.gameState().height - 25.0f)
      {
        e->kill();
      }
    }
  }
}

} // namespace space_shooter::ecs
