#include <space-shooter/ecs/entities/scene_exit.hpp>

#include <space-shooter/ecs/components/clock_component.hpp>
#include <space-shooter/ecs/components/text_blink_component.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

#include <filesystem>

namespace space_shooter::ecs {

SceneExit::SceneExit(const sf::Font& font, const std::string& texte) {
  add<ClockComponent>(sf::seconds(3.0f));
  //add<TextBlinkComponent>(font, texte);
}

SceneExit::SceneExit() {
  add<ClockComponent>(sf::seconds(3.0f));
}


} // namespace space_shooter::ecs
