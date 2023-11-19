#include <space-shooter/ecs/systems/clean_killed_ships_system.hpp>

#include <space-shooter/ecs/components/health_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

CleanKilledShipsSystem::CleanKilledShipsSystem()
    : System{
          type_list<HealthComponent>{}} {}

void CleanKilledShipsSystem::update(const sf::Time &delta_time,
                            std::vector<Entity *> &entities, Manager &manager) {

  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    const auto &health = e->get<HealthComponent>();

    if(health.health <= 0.0f)
    {
        e->kill();
    }
    
  }
}

} // namespace space_shooter::ecs
