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

    // MenuEntity
    auto font = manager.gameState().config.path_to_fonts / "Roboto-BoldCondensed.ttf";
    std::string texte = "Appuyez sur Entrer pour commencer la partie";
    manager.registerEntity<space_shooter::ecs::MenuEntity>();

    // Texte blink
    manager.registerSystem<space_shooter::ecs::TextBlinkSystem>();

    // RenderSystem
    manager.registerSystem<space_shooter::ecs::RenderingSystem>();
    
    // InputSystem
    manager.registerSystem<space_shooter::ecs::InputSystem>();

    // MenuSystem
    manager.registerSystem<space_shooter::ecs::MenuSystem>();
}

} // namespace space_shooter
