#include <space-shooter/ecs/systems/victory_system.hpp>

#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>
#include <space-shooter/ecs/manager.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

VictorySystem::VictorySystem()
    : System{
          type_list<TagComponent>{}} {}

void VictorySystem::update(const sf::Time &delta_time,
                            std::vector<Entity *> &entities, Manager &manager) {

  // Bool Victory
  bool victory = true;
  
  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    const auto &tag = e->get<TagComponent>();

    if(tag.tag == "EnemyShip" || tag.tag == "EnemySpawner")
    {
      if(e->isAlive())
      {
        victory = false; // Si un seul ennemi est encore en vie, alors pas de victoire
      }
    }
  }

  // Change Scene
  if(victory)
  {
    manager.gameState().switch_to_scene = GameState::Scene::Victory;
  }
}

} // namespace space_shooter::ecs
