#include <space-shooter/ecs/entities/background_music.hpp>

#include <space-shooter/ecs/components/music_component.hpp>

#include <filesystem>

namespace space_shooter::ecs {

BackgroundMusicEntity::BackgroundMusicEntity(const std::filesystem::path &audio_path) {
  add<MusicComponent>(audio_path, 50.0f);
}

} // namespace space_shooter::ecs
