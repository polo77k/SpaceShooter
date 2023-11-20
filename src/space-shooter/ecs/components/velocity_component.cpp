#include <space-shooter/ecs/components/velocity_component.hpp>

namespace space_shooter::ecs {
    
    VelocityComponent::VelocityComponent(float vx, float vy) : vx{vx}, vy{vy} {}
}