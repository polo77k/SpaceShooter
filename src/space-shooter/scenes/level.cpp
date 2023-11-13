#include <space-shooter/scenes/level.hpp>

#include <space-shooter/ecs/ecs.hpp>

namespace space_shooter {

void initLevel(ecs::Manager &manager) {
  // Vaisseau
  sf::Vector2f initialPosition(415.0f, 790.0f);
  sf::Vector2f initialVelocite(0.0f, 0.0f);
  auto imagePath = manager.gameState().config.path_to_textures / "spacecraft.png";

  manager.registerEntity<space_shooter::ecs::PlayerShipEntity>(initialPosition, imagePath, initialVelocite);

  // RenderSystem
  manager.registerSystem<space_shooter::ecs::RenderingSystem>();

  // Register entities/systems here
  // TODO
  //manager.gameState().switch_to_scene = GameState::Scene::Score;
}
} // namespace space_shooter
