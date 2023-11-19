#include <space-shooter/ecs/systems/health_bar_display_system.hpp>

#include <space-shooter/ecs/components/position_component.hpp>
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
          type_list<PositionComponent, TagComponent, SpriteComponent>{}} {}

void HealthBarDisplaySystem::update(const sf::Time &delta_time,
                            std::vector<Entity *> &entities, Manager &manager) {

  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    const auto &tag = e->get<TagComponent>();
    
    // Tag PlayerShip
    if(tag.tag == "PlayerShip")
    {
        const auto &health = e->get<HealthComponent>();

        for (auto e2 : entities)
        {
            assert(hasRequiredComponents(*e2));

            const auto &tag2 = e2->get<TagComponent>();
            auto &sprite2 = e2->get<SpriteComponent>();

            // Tag PlayerShipHealthBar
            if(tag2.tag == "PlayerShipHealthBar")
            {   
                // Display Bar
                sprite2.width = 1800 * (health.health / health.max_health);
            }
        }



    }


    

  }
}

} // namespace space_shooter::ecs
