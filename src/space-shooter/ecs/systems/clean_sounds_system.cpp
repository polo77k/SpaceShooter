#include <space-shooter/ecs/systems/clean_sounds_system.hpp>

#include <space-shooter/ecs/components/audio_component.hpp>
#include <space-shooter/ecs/components/clock_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

CleanSoundsSystem::CleanSoundsSystem()
    : System{
          type_list<AudioComponent, ClockComponent>{}} {}

void CleanSoundsSystem::update(const sf::Time &delta_time,
                            std::vector<Entity *> &entities, Manager &manager) {

  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    const auto &audio = e->get<AudioComponent>();
    const auto &clock = e->get<ClockComponent>();

    // Permet de supprimer les entités une fois le soundEffects joué
    if(clock.clock >= clock.cooldown)
    {
      e->kill();
    }
  }
}

} // namespace space_shooter::ecs
