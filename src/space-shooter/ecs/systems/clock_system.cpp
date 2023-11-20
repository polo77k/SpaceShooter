#include <space-shooter/ecs/systems/clock_system.hpp>

#include <space-shooter/ecs/components/clock_component.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

ClockSystem::ClockSystem()
    : System{
          type_list<ClockComponent>{}} {}

void ClockSystem::update(const sf::Time &delta_time,
                            std::vector<Entity *> &entities, Manager &manager) {

  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    auto &clock = e->get<ClockComponent>();
    clock.clock += delta_time;
  }
}

} // namespace space_shooter::ecs
