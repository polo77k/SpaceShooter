#include <SFML/Window/Keyboard.hpp>
#include <space-shooter/ecs/systems/text_blink_system.hpp>

#include <space-shooter/ecs/components/text_blink_component.hpp>
#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/ecs/system.hpp>
#include <space-shooter/game_state.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

TextBlinkSystem::TextBlinkSystem() : System{type_list<TextBlinkComponent>{}} {}

void TextBlinkSystem::update(const sf::Time &delta_time,
                         std::vector<Entity *> &entities, Manager &manager) {

  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    auto &textBlink = e->get<TextBlinkComponent>();

    textBlink.blinkTime -= delta_time.asSeconds();
    if(textBlink.blinkTime <= 0)
    {
        textBlink.isVisible = !textBlink.blinkTime;
        textBlink.blinkTime = 0.5f;
    }

    if(textBlink.isVisible)
    {
        manager.gameState().rendering_window->draw(textBlink.text);
    }
    
  }
}

} // namespace space_shooter::ecs