#include <space-shooter/ecs/components/health_component.hpp>

namespace space_shooter::ecs {
    
    HealthComponent::HealthComponent(float health) : health{health}, max_health{health} {}
}