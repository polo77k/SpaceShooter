#include <space-shooter/ecs/systems/shooting_system.hpp>

#include <space-shooter/ecs/entities/player_missile.hpp>
#include <space-shooter/ecs/entities/enemy_missile.hpp>
#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/clock_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

ShootingSystem::ShootingSystem()
    : System{
          type_list<InputComponent, PositionComponent, TagComponent, ClockComponent>{}} {}

void ShootingSystem::update(const sf::Time &delta_time,
                            std::vector<Entity *> &entities, Manager &manager) {

  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    const auto &input = e->get<InputComponent>();
    const auto &pos = e->get<PositionComponent>();
    const auto &tag = e->get<TagComponent>();
    auto &timer = e->get<ClockComponent>();

    // PlayerShip
    if(tag.tag == "PlayerShip")
    {
        if(input.shooting && timer.timer >= timer.cooldown_timer)
        {
            // new PlayerMissile
            sf::Vector2f initialPosition(pos.x + 35.0f, pos.y - 15.0f);
            sf::Vector2f initialVelocite(200.0f, 200.0f);
            auto imagePath = manager.gameState().config.path_to_textures / "PlayerMissile.png";
            manager.registerEntity<space_shooter::ecs::PlayerMissileEntity>(initialPosition, imagePath, initialVelocite);

            // reset cooldown
            timer.timer = 0.0f;
        }
    }

    // EnemyShip
    if(tag.tag == "EnemyShip")
    {
        if(timer.timer >= timer.cooldown_timer)
        {
            // new EnemyMissile
            sf::Vector2f positionEnemy(pos.x + 30.0f, pos.y + 40.0f);
            sf::Vector2f velociteEnemy(150.0f, 150.0f);
            auto imageMissile = manager.gameState().config.path_to_textures / "EnemyMissile.png";
            manager.registerEntity<space_shooter::ecs::EnemyMissileEntity>(positionEnemy, imageMissile, velociteEnemy);

            // reset cooldown
            timer.timer = 0.0f;
        }
    }
    
  }
}

} // namespace space_shooter::ecs
