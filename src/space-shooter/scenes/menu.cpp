#include <space-shooter/scenes/menu.hpp>

#include <space-shooter/ecs/ecs.hpp>

namespace space_shooter{

void menuGame(ecs::Manager& manager)
{
    // Background
    int window_width = manager.gameState().width;
    int window_heigth = manager.gameState().height;
    auto imagePath = manager.gameState().config.path_to_textures / "MenuSpaceShooter.png";
    manager.registerEntity<space_shooter::ecs::BackgroundEntity>(imagePath, window_width, window_heigth);

    // SceneMenu
    auto font_path = manager.gameState().config.path_to_fonts / "Roboto-BoldCondensed.ttf";
    std::string texte = "Appuyez sur Entree pour commencer la partie\n\nEchap pour quitter le jeu";
    manager.registerEntity<space_shooter::ecs::SceneMenu>(texte, font_path);

    // BackgroundMusic
    auto musicPath = manager.gameState().config.path_to_audio / "musique_menu.wav";
    manager.registerEntity<space_shooter::ecs::BackgroundMusicEntity>(musicPath, 50.0f);

    // MusicSystem
    manager.registerSystem<space_shooter::ecs::MusicSystem>();

    // RenderSystem
    manager.registerSystem<space_shooter::ecs::RenderingSystem>();
    
    // InputSystem
    manager.registerSystem<space_shooter::ecs::InputSystem>();

    // Texte blink
    manager.registerSystem<space_shooter::ecs::TextBlinkSystem>();

    // SceneMenuSystem
    manager.registerSystem<space_shooter::ecs::SceneMenuSystem>();
}

} // namespace space_shooter
