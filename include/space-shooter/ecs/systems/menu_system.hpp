#pragma once

#include <space-shooter/ecs/system.hpp>
#include <space-shooter/ecs/manager.hpp>

#include <vector>

namespace space_shooter::ecs {

class MenuSystem : public System {
public:
  MenuSystem();
  void update(const sf::Time &delta_time, std::vector<Entity *> &entities,
              Manager &manager) override;
};

} // namespace space_shooter::ecs