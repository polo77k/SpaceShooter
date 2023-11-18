#include <space-shooter/ecs/components/clock_component.hpp>

namespace space_shooter::ecs {
    
    ClockComponent::ClockComponent(float cooldown) : cooldown_timer{cooldown} {}
}