#include <space-shooter/ecs/systems/text_rendering_system.hpp>

#include <space-shooter/ecs/components/timer_component.hpp>
#include <space-shooter/ecs/components/text_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>
#include <space-shooter/ecs/manager.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

TextRenderingSystem::TextRenderingSystem()
    : System{
          type_list<TextComponent, TagComponent>{}} {}

void TextRenderingSystem::update(const sf::Time &delta_time,
                            std::vector<Entity *> &entities, Manager &manager) {

  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    auto &text = e->get<TextComponent>();
    const auto &tag = e->get<TagComponent>();

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


    // Tag Timer -> get Timer
    if(tag.tag == "Timer")
    {
        const auto &timer = e->get<TimerComponent>();
        auto t = std::to_string(timer.time.asSeconds());
        textDisplay.setString("Timer : " + t);
    }

    textDisplay.setFont(text.font);
    textDisplay.setCharacterSize(text.characterSize);
    textDisplay.setPosition(text.pos.x, text.pos.y);
    textDisplay.setColor(text.color);

    // Draw Text
    manager.gameState().rendering_window->draw(textDisplay);
  }
}

} // namespace space_shooter::ecs
