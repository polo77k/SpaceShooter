#include <space-shooter/scenes/menu.hpp>

#include <space-shooter/ecs/ecs.hpp>

namespace space_shooter{

void menuGame(ecs::Manager& manager)
{
    // Background
    int window_width = manager.gameState().width;
    int window_heigth = manager.gameState().height;
    auto imagePath = manager.gameState().config.path_to_textures / "menu.jpg";
    manager.registerEntity<space_shooter::ecs::BackgroundEntity>(imagePath, window_width, window_heigth);

    // SceneMenu
    auto font = manager.gameState().config.path_to_fonts / "Roboto-BoldCondensed.ttf";
    std::string texte = "Appuyez sur Entrer pour commencer la partie";
    manager.registerEntity<space_shooter::ecs::SceneMenu>();

    // Texte blink
    manager.registerSystem<space_shooter::ecs::TextBlinkSystem>();

    // RenderSystem
    manager.registerSystem<space_shooter::ecs::RenderingSystem>();
    
    // InputSystem
    manager.registerSystem<space_shooter::ecs::InputSystem>();

    // SceneMenuSystem
    manager.registerSystem<space_shooter::ecs::SceneMenuSystem>();
}

} // namespace space_shooter
