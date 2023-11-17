#include <space-shooter/ecs/entities/menu_entity.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/components/text_blink_component.hpp>

#include <SFML/Graphics.hpp>

#include <filesystem>

namespace space_shooter::ecs {

MenuEntity::MenuEntity(const sf::Font& font, const std::string& texte) {
  add<InputComponent>();
  //add<TextBlinkComponent>(font, texte);
}

MenuEntity::MenuEntity() {
  add<InputComponent>();
}


} // namespace space_shooter::ecs
