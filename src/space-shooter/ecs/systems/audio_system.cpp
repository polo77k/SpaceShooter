#include <space-shooter/ecs/systems/audio_system.hpp>

#include <space-shooter/ecs/components/audio_component.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

AudioSystem::AudioSystem()
    : System{
          type_list<AudioComponent>{}} {}

void AudioSystem::update(const sf::Time &delta_time,
                            std::vector<Entity *> &entities, Manager &manager) {
  
  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    auto &audio = e->get<AudioComponent>();

    if(!audio.playAudio)
    {
        if(audio.soundBuffer.loadFromFile(audio.audio_path.string()))
        {
            audio.sound = sf::Sound(audio.soundBuffer);
            audio.sound.setVolume(audio.volume);
            audio.sound.play();
        }
        else
        {
            std::cerr << "Probleme audio : " << audio.audio_path.string() << std::endl;
        }

        audio.playAudio = true;
    }
  }
}

} // namespace space_shooter::ecs
