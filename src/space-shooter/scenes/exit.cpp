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
    
    // BackgroundMusic
    auto musicPath = manager.gameState().config.path_to_audio / "game_over.wav";
    manager.registerEntity<space_shooter::ecs::BackgroundMusicEntity>(musicPath);

    // SceneExit
    auto font_path = manager.gameState().config.path_to_fonts / "Roboto-BoldCondensed.ttf";
    std::string texte = "Retour vers le menu dans \nquelques secondes...";
    manager.registerEntity<space_shooter::ecs::SceneExit>(texte, font_path);

    // MusicSystem
    manager.registerSystem<space_shooter::ecs::MusicSystem>();

    // RenderingSystem
    manager.registerSystem<space_shooter::ecs::RenderingSystem>();

    // SceneExit
    manager.registerEntity<space_shooter::ecs::SceneExit>();
    
    // ClockSystem
    manager.registerSystem<space_shooter::ecs::ClockSystem>();
    
    // TextRenderingSysteme
    manager.registerSystem<space_shooter::ecs::TextRenderingSystem>();

    // SceneExitSystem
    manager.registerSystem<space_shooter::ecs::SceneExitSystem>();
  }

} // namespace space_shooter
