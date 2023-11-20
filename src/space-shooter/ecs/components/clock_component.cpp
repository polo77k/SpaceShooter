#include <space-shooter/ecs/components/clock_component.hpp>

namespace space_shooter::ecs {
    
    ClockComponent::ClockComponent(sf::Time cooldown) : cooldown{cooldown} {}
}