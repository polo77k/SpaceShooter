#include <space-shooter/ecs/systems/music_system.hpp>

#include <space-shooter/ecs/components/music_component.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Audio/Music.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

MusicSystem::MusicSystem()
    : System{
          type_list<MusicComponent>{}} {}

void MusicSystem::update(const sf::Time &delta_time,
                            std::vector<Entity *> &entities, Manager &manager) {  
  
  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    auto &music = e->get<MusicComponent>();

    music.sound.setVolume(music.volume);
    
    if(!music.jouer)
    {
        if(music.sound.openFromFile(music.audio_path.string()))
        {
            music.sound.setLoop(true);
            music.sound.play();
        }
        else
        {
            std::cerr << "Probleme music : " << music.audio_path.string() << std::endl;
        }
        music.jouer = true;
    }
  }
}

} // namespace space_shooter::ecs
