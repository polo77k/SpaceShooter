#include <space-shooter/scenes/exit.hpp>

#include <space-shooter/ecs/ecs.hpp>

namespace space_shooter
{

  void exitGame(ecs::Manager& manager)
  {
    // SceneExit
    manager.registerEntity<space_shooter::ecs::SceneExit>();
    
    // ClockSystem
    manager.registerSystem<space_shooter::ecs::ClockSystem>();

    // SceneExitSystem
    manager.registerSystem<space_shooter::ecs::SceneExitSystem>();
  }

} // namespace space_shooter
