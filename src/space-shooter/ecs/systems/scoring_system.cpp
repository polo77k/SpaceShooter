#include <space-shooter/ecs/systems/scoring_system.hpp>

#include <space-shooter/ecs/components/score_component.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>
#include <space-shooter/ecs/manager.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

ScoringSystem::ScoringSystem()
    : System{
          type_list<ScoreComponent>{}} {}

void ScoringSystem::update(const sf::Time &delta_time,
                            std::vector<Entity *> &entities, Manager &manager) {

  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    
  }
}

} // namespace space_shooter::ecs
