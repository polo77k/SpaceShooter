#pragma once

#include <space-shooter/ecs/component.hpp>

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include <filesystem>

namespace space_shooter::ecs {

struct AudioComponent : Component {
  std::filesystem::path audio_path;
  float volume = 0.f;
  bool playAudio;
  sf::Sound sound;
  sf::SoundBuffer soundBuffer;

  AudioComponent(const std::filesystem::path &audio_path, const float volume, bool playAudio = false);
  AudioComponent() = delete;
};

} // namespace space_shooter::ecs