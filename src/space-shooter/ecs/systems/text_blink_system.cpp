#include <space-shooter/ecs/systems/text_blink_system.hpp>

#include <space-shooter/ecs/components/text_blink_component.hpp>
#include <space-shooter/ecs/components/text_component.hpp>
#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/ecs/system.hpp>
#include <space-shooter/game_state.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

TextBlinkSystem::TextBlinkSystem() : System{type_list<TextBlinkComponent, TextComponent>{}} {}

void TextBlinkSystem::update(const sf::Time &delta_time,
                         std::vector<Entity *> &entities, Manager &manager) {

  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    auto &textBlink = e->get<TextBlinkComponent>();
    auto &text = e->get<TextComponent>();

    // Permet de switch entre un texte visible et non visible
    textBlink.blinkTime -= delta_time;
    if(textBlink.blinkTime <= sf::Time::Zero)
    {
        textBlink.isVisible = !textBlink.isVisible;
        textBlink.blinkTime = sf::seconds(0.5f);
    }

    // Affiche le texte uniquement quand cela est permit
    if(textBlink.isVisible)
    {    
        sf::Text textDisplay;
        textDisplay.setString(text.text);

        if(!text.loaded)
        {
            if(text.font.loadFromFile(text.font_path.string()))
            {
                text.loaded = true;
            }
            else
            {
                std::cerr << "Probleme font : " << text.font_path.string() << std::endl;
            }
        }

        textDisplay.setFont(text.font);
        textDisplay.setCharacterSize(text.characterSize);
        textDisplay.setPosition(text.pos.x, text.pos.y);
        textDisplay.setColor(text.color);
        
        // Draw Text if is visible
        manager.gameState().rendering_window->draw(textDisplay);
    }
  }
}

} // namespace space_shooter::ecs