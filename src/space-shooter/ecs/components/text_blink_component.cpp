#include <space-shooter/ecs/components/text_blink_component.hpp>

namespace space_shooter::ecs {

    TextBlinkComponent::TextBlinkComponent(sf::Time blinkTime) : blinkTime{blinkTime} {}
}