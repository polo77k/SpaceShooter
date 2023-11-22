#include <SFML/Window/Keyboard.hpp>
#include <space-shooter/ecs/systems/scene_rules_system.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/ecs/system.hpp>
#include <space-shooter/game_state.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

SceneRulesSystem::SceneRulesSystem() : System{type_list<InputComponent>{}} {}

void SceneRulesSystem::update(const sf::Time &delta_time,
                         std::vector<Entity *> &entities, Manager &manager) {

  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    const auto &input = e->get<InputComponent>();

    // detect keypressed to change scene
    if(input.escape)
    {
      manager.gameState().switch_to_scene = GameState::Scene::Menu;
    }
  }
}

} // namespace space_shooter::ecs