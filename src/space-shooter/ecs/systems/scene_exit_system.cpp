#include <SFML/Window/Keyboard.hpp>
#include <space-shooter/ecs/systems/scene_exit_system.hpp>

#include <space-shooter/ecs/components/clock_component.hpp>
#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/ecs/system.hpp>
#include <space-shooter/game_state.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

SceneExitSystem::SceneExitSystem() : System{type_list<ClockComponent>{}} {}

void SceneExitSystem::update(const sf::Time &delta_time,
                         std::vector<Entity *> &entities, Manager &manager) {

  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    const auto &clock = e->get<ClockComponent>();

    // Change scene after cooldown
    if(clock.clock >= clock.cooldown)
    {
      manager.gameState().switch_to_scene = GameState::Scene::Menu;
    }
  }
}

} // namespace space_shooter::ecs