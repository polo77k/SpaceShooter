#include <space-shooter/ecs/systems/timer_system.hpp>

#include <space-shooter/ecs/components/timer_component.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>
#include <space-shooter/ecs/manager.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

TimerSystem::TimerSystem()
    : System{
          type_list<TimerComponent>{}} {}

void TimerSystem::update(const sf::Time &delta_time,
                            std::vector<Entity *> &entities, Manager &manager) {

  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    auto &timer = e->get<TimerComponent>();
    timer.time -= delta_time;

    if(timer.time <= sf::Time::Zero)
    {
        manager.gameState().switch_to_scene = GameState::Scene::Exit;
    }
  }
}

} // namespace space_shooter::ecs
