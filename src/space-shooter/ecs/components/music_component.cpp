#include <space-shooter/ecs/components/music_component.hpp>

namespace space_shooter::ecs {
    
    MusicComponent::MusicComponent(const std::filesystem::path audio_path, const float volume, bool jouer) : audio_path{audio_path},
            volume{volume}, jouer{jouer} {}
}