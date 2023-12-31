#include <SFML/Window/Keyboard.hpp>
#include <space-shooter/ecs/systems/input_system.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/ecs/system.hpp>
#include <space-shooter/game_state.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

InputSystem::InputSystem() : System{type_list<InputComponent>{}} {}

void InputSystem::update(const sf::Time &delta_time,
                         std::vector<Entity *> &entities, Manager &manager) {

  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    auto &input = e->get<InputComponent>();

    // TODO : reset detected input from keyboard (put all value of component to false)
    input.move_left = false; input.move_right = false; input.move_top = false; input.move_bottom = false;
    input.shooting = false; input.escape = false; input.enter = false;
    
    // TODO: detect keypressed with SFML and set the boolean state accordingly
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
      input.move_left = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
      input.move_right = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
      input.move_top = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
      input.move_bottom = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
      input.shooting = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
      input.escape = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
      input.enter = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
      input.rules = true;
    }
  }
}

} // namespace space_shooter::ecs