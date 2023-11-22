#include <space-shooter/scenes/level.hpp>

#include <space-shooter/ecs/ecs.hpp>

namespace space_shooter {

void initLevel(ecs::Manager &manager) {
  // Background
  int window_width = manager.gameState().width;
  int window_heigth = manager.gameState().height;
  auto imageGame = manager.gameState().config.path_to_textures / "game.jpg";
  manager.registerEntity<space_shooter::ecs::BackgroundEntity>(imageGame, window_width, window_heigth);

  // PlayerShip
  sf::Vector2f initialPosition(manager.gameState().width/2.0f - 40.0f, manager.gameState().height - 110.0f);
  sf::Vector2f initialVelocite(200.0f, 200.0f);
  auto imagePath = manager.gameState().config.path_to_textures / "spacecraft.png";
  manager.registerEntity<space_shooter::ecs::PlayerShipEntity>(initialPosition, imagePath, initialVelocite);

  // EnemySpawner
  sf::Vector2f positionEnemy(90.0f, 20.0f);
  sf::Vector2f velociteEnemy(100.0f, 0.0f);
  auto imageEnemy = manager.gameState().config.path_to_textures / "EnemySpawner.png";
  manager.registerEntity<space_shooter::ecs::EnemySpawnerEntity>(positionEnemy, imageEnemy, velociteEnemy);

  // PlayerShipHealthBar
  sf::Vector2f initialBar(0.0f, 0.0f);
  auto imageBar = manager.gameState().config.path_to_textures / "HealthBar.png";
  manager.registerEntity<space_shooter::ecs::PlayerShipHealthBarEntity>(initialBar, imageBar);

  // BackgroundMusic
  auto musicPath = manager.gameState().config.path_to_audio / "music_fight.wav";
  manager.registerEntity<space_shooter::ecs::BackgroundMusicEntity>(musicPath, 30.0f);

  // MusicSystem
  manager.registerSystem<space_shooter::ecs::MusicSystem>();

  // EnemySystem
  manager.registerSystem<space_shooter::ecs::EnemySpawnerSystem>();

  // MovementSpawnerSystem
  manager.registerSystem<space_shooter::ecs::MovementSpawnerSystem>();

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

  // CleanMissilesSystem
  manager.registerSystem<space_shooter::ecs::CleanMissilesSystem>();

  // PlayerDeathSystem
  manager.registerSystem<space_shooter::ecs::PlayerDeathSystem>();

  // HealthBarDisplaySystem
  manager.registerSystem<space_shooter::ecs::HealthBarDisplaySystem>();

  // Timer
  sf::Time initialTime = sf::seconds(90.0f);
  auto font_path = manager.gameState().config.path_to_fonts / "Roboto-BoldCondensed.ttf";
  manager.registerEntity<space_shooter::ecs::LevelTimerEntity>(initialTime, font_path);

  // TimerSystem
  manager.registerSystem<space_shooter::ecs::TimerSystem>();

  // TextRenderingSystem
  manager.registerSystem<space_shooter::ecs::TextRenderingSystem>();

  // ScoreDisplay
  manager.registerEntity<space_shooter::ecs::ScoreDisplayEntity>(font_path);

  // AudioSystem
  manager.registerSystem<space_shooter::ecs::AudioSystem>();

  // CleanSoundsSystem
  manager.registerSystem<space_shooter::ecs::CleanSoundsSystem>();

  // EnemyChasingSystem
  manager.registerSystem<space_shooter::ecs::EnemyChasingSystem>();

  // VictorySystem
  manager.registerSystem<space_shooter::ecs::VictorySystem>();

  // TODO
  //manager.gameState().switch_to_scene = GameState::Scene::Score;
}
} // namespace space_shooter
