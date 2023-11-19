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
  sf::Vector2f initialPosition(manager.gameState().width/2.0f - 40.0f, manager.gameState().height - 110.0f);
  sf::Vector2f initialVelocite(200.0f, 200.0f);
  auto imagePath = manager.gameState().config.path_to_textures / "spacecraft.png";
  manager.registerEntity<space_shooter::ecs::PlayerShipEntity>(initialPosition, imagePath, initialVelocite);

  // EnemySpawner
  sf::Vector2f initialEnemy(manager.gameState().width/2.0f - 60.0f, 20.0f);
  auto imageEnemy = manager.gameState().config.path_to_textures / "EnemySpawner.png";
  manager.registerEntity<space_shooter::ecs::EnemySpawnerEntity>(initialEnemy, imageEnemy);

  // EnemySystem
  manager.registerSystem<space_shooter::ecs::EnemySpawnerSystem>();

  // RenderSystem
  manager.registerSystem<space_shooter::ecs::RenderingSystem>();

  // InputSystem
  manager.registerSystem<space_shooter::ecs::InputSystem>();

  // MovementSystem
  manager.registerSystem<space_shooter::ecs::MovementSystem>();

  // ClockSystem
  manager.registerSystem<space_shooter::ecs::ClockSystem>();

  // ShootingSystem
  manager.registerSystem<space_shooter::ecs::ShootingSystem>();

  // CollisionSystem
  manager.registerSystem<space_shooter::ecs::CollisionSystem>();

  // CleanKilledShipsSystem
  manager.registerSystem<space_shooter::ecs::CleanKilledShipsSystem>();

  // SceneLevelSystem
  manager.registerSystem<space_shooter::ecs::SceneLevelSystem>();

  // TODO
  //manager.gameState().switch_to_scene = GameState::Scene::Score;
}
} // namespace space_shooter
