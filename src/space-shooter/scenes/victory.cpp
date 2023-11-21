#include <space-shooter/scenes/victory.hpp>

#include <space-shooter/ecs/ecs.hpp>

namespace space_shooter{

void victoryScene(ecs::Manager& manager)
{
    // Background
    int window_width = manager.gameState().width;
    int window_heigth = manager.gameState().height;
    auto imagePath = manager.gameState().config.path_to_textures / "victory.png";
    manager.registerEntity<space_shooter::ecs::BackgroundEntity>(imagePath, window_width, window_heigth);

    // SceneVictory
    auto font_path = manager.gameState().config.path_to_fonts / "Roboto-BoldCondensed.ttf";
    std::string texte = "Victoire !!!";
    manager.registerEntity<space_shooter::ecs::SceneVictory>(texte, font_path);

    // BackgroundMusic
    auto musicPath = manager.gameState().config.path_to_audio / "victory.wav";
    manager.registerEntity<space_shooter::ecs::BackgroundMusicEntity>(musicPath, 50.0f);

    // MusicSystem
    manager.registerSystem<space_shooter::ecs::MusicSystem>();

    // RenderSystem
    manager.registerSystem<space_shooter::ecs::RenderingSystem>();

    // ClockSystem
    manager.registerSystem<space_shooter::ecs::ClockSystem>();

    // TextRenderingSysteme
    manager.registerSystem<space_shooter::ecs::TextRenderingSystem>();

    // SceneVictorySystem
    manager.registerSystem<space_shooter::ecs::SceneVictorySystem>();
}

} // namespace space_shooter
