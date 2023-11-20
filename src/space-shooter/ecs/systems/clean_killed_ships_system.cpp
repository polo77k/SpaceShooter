#include <space-shooter/ecs/systems/clean_killed_ships_system.hpp>

#include <space-shooter/ecs/components/health_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/score_component.hpp>
#include <space-shooter/ecs/entities/score_display.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

CleanKilledShipsSystem::CleanKilledShipsSystem()
    : System{
          type_list<HealthComponent, TagComponent>{}} {}

void CleanKilledShipsSystem::update(const sf::Time &delta_time,
                            std::vector<Entity *> &entities, Manager &manager) {

  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    const auto &health = e->get<HealthComponent>();
    const auto &tag = e->get<TagComponent>();

    if(health.health <= 0.0f)
    {
      if(tag.tag == "EnemyShip")
      { 
        // Permet d'ajouter 100 points par kill
        manager.sendToEntity<ScoreDisplayEntity>([&](auto &scoreDisp)
        {
          auto &score = scoreDisp.get<ScoreComponent>();
          score.score += 100;
        });
      }
      e->kill();
    }
    
  }
}

} // namespace space_shooter::ecs
