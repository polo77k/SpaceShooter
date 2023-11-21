#include <space-shooter/ecs/entities/sound_effects.hpp>

#include <space-shooter/ecs/components/audio_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/clock_component.hpp>

#include <SFML/System/Time.hpp>

namespace space_shooter::ecs {

SoundEffetsEntity::SoundEffetsEntity(const std::filesystem::path &audio_path, const float volume)
{
  add<TagComponent>("Audio");
  add<AudioComponent>(audio_path, volume);
  add<ClockComponent>(sf::seconds(5.0f));
}

} // namespace space_shooter::ecs
