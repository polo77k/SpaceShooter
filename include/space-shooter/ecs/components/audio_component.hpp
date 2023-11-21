#pragma once

#include <space-shooter/ecs/component.hpp>

#include <filesystem>

namespace space_shooter::ecs {

struct AudioComponent : Component {
  std::filesystem::path audio_path;
  float volume = 0.f;
  bool playAudio;

  AudioComponent(const std::filesystem::path audio_path, const float volume, bool playAudio = false);
  AudioComponent() = delete;
};

} // namespace space_shooter::ecs