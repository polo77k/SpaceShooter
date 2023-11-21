#include <space-shooter/ecs/systems/enemy_chasing_system.hpp>

#include <space-shooter/ecs/entities/player_ship.hpp>

#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/velocity_component.hpp>

#include <SFML/System/Vector2.hpp>

#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <cmath>

namespace space_shooter::ecs {

EnemyChasingSystem::EnemyChasingSystem()
    : System{
          type_list<PositionComponent, TagComponent, VelocityComponent>{}} {}

void EnemyChasingSystem::update(const sf::Time &delta_time,
                            std::vector<Entity *> &entities, Manager &manager) {

    const auto posShip = manager.getFromEntity<PlayerShipEntity>([](auto &player){return player.get<PositionComponent>();});

    if(!posShip.has_value())
    {
        return;
    }
  
    for (auto e : entities) {
        assert(hasRequiredComponents(*e));

        const auto &pos = e->get<PositionComponent>();
        const auto &tag = e->get<TagComponent>();
        auto &vel = e->get<VelocityComponent>();

        // Tag EnemyShip
        if(tag.tag == "EnemyShip")
        {
            sf::Vector2f direction;
            direction.x = posShip.value().x - pos.x;
            direction.y = posShip.value().y - pos.y;

            float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
            if(length != 0)
            {
                direction.x = direction.x / length;
                direction.y = direction.y / length;
            }

            vel.vx = direction.x * 100.0f;
            vel.vy = direction.y * 100.0f;
        }
  }
}

} // namespace space_shooter::ecs
