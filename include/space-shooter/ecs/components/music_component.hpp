#pragma once

#include <space-shooter/ecs/component.hpp>

#include <SFML/Audio/Music.hpp>

#include <filesystem>

namespace space_shooter::ecs {

struct MusicComponent : Component {
  std::filesystem::path audio_path;
  float volume = 0.f;
  bool jouer;
  sf::Music sound;

  MusicComponent(const std::filesystem::path &audio_path, const float volume, bool jouer = false);
  MusicComponent() = delete;
};

} // namespace space_shooter::ecs