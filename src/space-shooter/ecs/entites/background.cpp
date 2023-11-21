#include <space-shooter/ecs/entities/background.hpp>

namespace space_shooter::ecs {

BackgroundEntity::BackgroundEntity(const std::filesystem::path &texture_path,
                                   int window_width, int window_height) {
  add<PositionComponent>(0.f, 0.f);
  add<TextureComponent>(texture_path, false);
  add<SpriteComponent>(window_width, window_height);
}

} // namespace space_shooter::ecs
