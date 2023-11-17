#include <space-shooter/ecs/components/text_blink_component.hpp>

namespace space_shooter::ecs {

    TextBlinkComponent::TextBlinkComponent(const sf::Font& font, const std::string& texte)
    {
        text.setFont(font);
        text.setString(texte);
    }
}