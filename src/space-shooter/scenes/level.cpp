#include <space-shooter/scenes/level.hpp>

#include <space-shooter/ecs/ecs.hpp>

namespace space_shooter {

void initLevel(ecs::Manager &manager) {
  // Background
  int window_width = manager.gameState().width;
  int window_heigth = manager.gameState().height;
  auto imageGame = manager.gameState().config.path_to_textures / "game.jpg";
  manager.registerEntity<space_shooter::ecs::BackgroundEntity>(imageGame, window_width, window_heigth);

  // Vaisseau
  sf::Vector2f initialPosition(manager.gameState().width/2.0f - 30.0f, manager.gameState().height - 110.0f);
  sf::Vector2f initialVelocite(200.0f, 200.0f);
  auto imagePath = manager.gameState().config.path_to_textures / "spacecraft.png";
  manager.registerEntity<space_shooter::ecs::PlayerShipEntity>(initialPosition, imagePath, initialVelocite);

  // RenderSystem
  manager.registerSystem<space_shooter::ecs::RenderingSystem>();

  // InputSystem
  manager.registerSystem<space_shooter::ecs::InputSystem>();

  // MovementSystem
  manager.registerSystem<space_shooter::ecs::MovementSystem>();

  // Register entities/systems here
  // TODO
  //manager.gameState().switch_to_scene = GameState::Scene::Score;
}
} // namespace space_shooter
