#include <space-shooter/ecs/systems/movement_system.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/velocity_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

MovementSystem::MovementSystem()
    : System{
          type_list<VelocityComponent, PositionComponent, InputComponent>{}} {}

void MovementSystem::update(const sf::Time &delta_time,
                            std::vector<Entity *> &entities, Manager &manager) {

  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    const auto &vel = e->get<VelocityComponent>();
    auto &pos = e->get<PositionComponent>();
    const auto &input = e->get<InputComponent>();
    const auto &sprite = e->get<SpriteComponent>();

    // TODO : update position coordinates depending on which input was triggered
    // the formula is simple : coord = coord +/- (velocity * deltatime)
    // the velocity needs to be > 100 to observe any significant change
    if(input.move_left && pos.x - vel.vx * delta_time.asSeconds() > 0)
    {
      pos.x -= vel.vx * delta_time.asSeconds();
    }
    if(input.move_right && pos.x + vel.vx * delta_time.asSeconds() + sprite.width*sprite.size < manager.gameState().width)
    {
      pos.x += vel.vx * delta_time.asSeconds();
    }
    if(input.move_top && pos.y - vel.vy * delta_time.asSeconds() > 0)
    {
      pos.y -= vel.vy * delta_time.asSeconds();
    }
    if(input.move_bottom && pos.y + vel.vy * delta_time.asSeconds() + sprite.height*sprite.size < manager.gameState().height)
    {
      pos.y += vel.vy * delta_time.asSeconds();
    }
  }
}

} // namespace space_shooter::ecs
