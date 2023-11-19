#include <space-shooter/scenes/exit.hpp>

#include <space-shooter/ecs/ecs.hpp>

namespace space_shooter
{

  void exitGame(ecs::Manager& manager)
  {
    // Background
    int window_width = manager.gameState().width;
    int window_heigth = manager.gameState().height;
    auto imagePath = manager.gameState().config.path_to_textures / "GameOver.png";
    manager.registerEntity<space_shooter::ecs::BackgroundEntity>(imagePath, window_width, window_heigth);
    
    // RenderingSystem
    manager.registerSystem<space_shooter::ecs::RenderingSystem>();

    // SceneExit
    manager.registerEntity<space_shooter::ecs::SceneExit>();
    
    // ClockSystem
    manager.registerSystem<space_shooter::ecs::ClockSystem>();

    // SceneExitSystem
    manager.registerSystem<space_shooter::ecs::SceneExitSystem>();
  }

} // namespace space_shooter
