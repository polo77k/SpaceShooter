#include <SFML/Window/Keyboard.hpp>
#include <space-shooter/ecs/systems/menu_system.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/ecs/system.hpp>
#include <space-shooter/game_state.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

MenuSystem::MenuSystem() : System{type_list<InputComponent>{}} {}

void MenuSystem::update(const sf::Time &delta_time,
                         std::vector<Entity *> &entities, Manager &manager) {

  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    auto &input = e->get<InputComponent>();

    // detect keypressed to change scene
    if(input.enter)
    {
      manager.gameState().switch_to_scene = GameState::Scene::Level;
    }
    if(input.escape)
    {
      manager.gameState().running = false; // stop the game
    }
    
  }
}

} // namespace space_shooter::ecs