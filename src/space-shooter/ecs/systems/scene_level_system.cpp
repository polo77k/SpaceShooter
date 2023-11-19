#include <SFML/Window/Keyboard.hpp>
#include <space-shooter/ecs/systems/scene_level_system.hpp>

#include <space-shooter/ecs/components/health_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/ecs/system.hpp>
#include <space-shooter/game_state.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

SceneLevelSystem::SceneLevelSystem() : System{type_list<TagComponent, HealthComponent>{}} {}

void SceneLevelSystem::update(const sf::Time &delta_time,
                         std::vector<Entity *> &entities, Manager &manager) {

  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    const auto &tag = e->get<TagComponent>();
    const auto &health = e->get<HealthComponent>();

    // detect keypressed to change scene
    if(tag.tag == "PlayerShip" && health.health <= 0.0f)
    {
      manager.gameState().switch_to_scene = GameState::Scene::Exit;
    }
  }
}

} // namespace space_shooter::ecs