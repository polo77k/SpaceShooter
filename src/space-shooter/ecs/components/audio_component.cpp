#include <space-shooter/ecs/components/audio_component.hpp>

namespace space_shooter::ecs {
    
    AudioComponent::AudioComponent(const std::filesystem::path &audio_path, const float volume, bool playAudio) : audio_path{audio_path}, 
            volume{volume}, playAudio{playAudio} {}
}