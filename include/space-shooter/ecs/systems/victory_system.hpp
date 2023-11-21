#pragma once

#include <space-shooter/ecs/system.hpp>

#include <vector>

namespace space_shooter::ecs {

class VictorySystem : public System {
public:
  VictorySystem();
  void update(const sf::Time &delta_time, std::vector<Entity *> &entities,
              Manager &manager) override;
};

} // namespace space_shooter::ecs