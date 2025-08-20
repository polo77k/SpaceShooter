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
    input.shooting = false; input.enter = false; input.escape = false;
    
    // TODO: detect keypressed with SFML and set the boolean state accordingly
    // Direction
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
      input.move_left = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
      input.move_right = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
      input.move_top = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
      input.move_bottom = true;
    }

    // Shoot
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
      input.shooting = true;
    }

    // Game and Rules
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
      input.enter = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
      input.rules = true;
    }

    // Specific logic for Escape
    bool escape_now = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
    if (input.prev_escape && !escape_now) {
      input.escape = true;
    } else {
      input.escape = false;
    }
    input.prev_escape = escape_now;
  }
}

} // namespace space_shooter::ecs