#include <space-shooter/ecs/systems/shooting_system.hpp>

#include <space-shooter/ecs/entities/player_missile.hpp>
#include <space-shooter/ecs/entities/enemy_missile.hpp>
#include <space-shooter/ecs/entities/sound_effects.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/clock_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

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
    auto &clock = e->get<ClockComponent>();

    // PlayerShip
    if(tag.tag == "PlayerShip")
    {
        if(input.shooting && clock.clock >= clock.cooldown)
        {
            // new PlayerMissile
            sf::Vector2f initialPosition(pos.x + 35.0f, pos.y - 15.0f);
            sf::Vector2f initialVelocite(200.0f, 200.0f);
            auto imagePath = manager.gameState().config.path_to_textures / "PlayerMissile.png";
            manager.registerEntity<space_shooter::ecs::PlayerMissileEntity>(initialPosition, imagePath, initialVelocite);

            // new SoundEffect
            auto soundPath = manager.gameState().config.path_to_audio / "missile_vaisseau.wav";
            manager.registerEntity<space_shooter::ecs::SoundEffetsEntity>(soundPath, 20.0f);

            // reset cooldown
            clock.clock = sf::Time::Zero;
        }
    }

    // EnemyShip
    if(tag.tag == "EnemyShip")
    {
        if(clock.clock >= clock.cooldown)
        {
            // new EnemyMissile
            sf::Vector2f positionEnemy(pos.x + 30.0f, pos.y + 40.0f);
            sf::Vector2f velociteEnemy(150.0f, 150.0f);
            auto imageMissile = manager.gameState().config.path_to_textures / "EnemyMissile.png";
            manager.registerEntity<space_shooter::ecs::EnemyMissileEntity>(positionEnemy, imageMissile, velociteEnemy);

            // new SoundEffect
            auto soundPath2 = manager.gameState().config.path_to_audio / "missile_enemy.wav";
            manager.registerEntity<space_shooter::ecs::SoundEffetsEntity>(soundPath2, 70.0f);

            // reset cooldown
            clock.clock = sf::Time::Zero;
        }
    }
  }
}

} // namespace space_shooter::ecs
