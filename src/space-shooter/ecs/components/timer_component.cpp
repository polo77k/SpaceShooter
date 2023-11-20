#include <space-shooter/ecs/components/timer_component.hpp>

namespace space_shooter::ecs {
    
    TimerComponent::TimerComponent(sf::Time time) : time{time} {}
}