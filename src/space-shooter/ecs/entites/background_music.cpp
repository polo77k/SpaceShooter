#include <space-shooter/ecs/entities/background_music.hpp>

namespace space_shooter::ecs {

BackgroundMusicEntity::BackgroundMusicEntity(const std::filesystem::path &audio_path, const float volume) {
  add<MusicComponent>(audio_path, volume);
}

} // namespace space_shooter::ecs
