#include <space-shooter/ecs/systems/health_bar_display_system.hpp>

#include <space-shooter/ecs/entities/player_ship.hpp>

#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/health_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

HealthBarDisplaySystem::HealthBarDisplaySystem()
    : System{
          type_list<TagComponent, SpriteComponent>{}} {}

void HealthBarDisplaySystem::update(const sf::Time &delta_time,
                            std::vector<Entity *> &entities, Manager &manager) {

    auto healthShip = manager.getFromEntity<PlayerShipEntity>([](auto &score){return score.get<HealthComponent>();});

    if(!healthShip.has_value())
    {
        return;
    }
    
    for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    const auto &tag = e->get<TagComponent>();
    auto &sprite = e->get<SpriteComponent>();
    
    // Tag PlayerShip
    if(tag.tag == "PlayerShipHealthBar")
    {
        // Display Bar
        sprite.width = 1800 * (healthShip.value().health / healthShip.value().max_health);
    }
  }
}

} // namespace space_shooter::ecs
