#include <space-shooter/scenes/rules.hpp>

#include <space-shooter/ecs/ecs.hpp>

namespace space_shooter
{

  void rulesMenu(ecs::Manager& manager)
  {
    // Background
    int window_width = manager.gameState().width;
    int window_heigth = manager.gameState().height;
    auto imagePath = manager.gameState().config.path_to_textures / "rules.png";
    manager.registerEntity<space_shooter::ecs::BackgroundEntity>(imagePath, window_width, window_heigth);

    // SceneVictory
    auto font_path = manager.gameState().config.path_to_fonts / "Roboto-BoldCondensed.ttf";
    std::string texte = "Regles du jeu :\nVous devez detruire tout les vaisseaux\nennemies, ainsi que le vaisseau mere\npour gagner.\n\nTouches :\nFleches directionnelles pour se deplacer.\nEspace pour tirer.\n\n\n\n\n\n\nEchap pour retourner au Menu.";
    manager.registerEntity<space_shooter::ecs::SceneRules>(texte, font_path);

    // BackgroundMusic
    auto musicPath = manager.gameState().config.path_to_audio / "music_rules.wav";
    manager.registerEntity<space_shooter::ecs::BackgroundMusicEntity>(musicPath, 50.0f);

    // MusicSystem
    manager.registerSystem<space_shooter::ecs::MusicSystem>();

    // RenderSystem
    manager.registerSystem<space_shooter::ecs::RenderingSystem>();

    // TextRenderingSysteme
    manager.registerSystem<space_shooter::ecs::TextRenderingSystem>();

    // InputSystem
    manager.registerSystem<space_shooter::ecs::InputSystem>();

    // SceneRulesSystem
    manager.registerSystem<space_shooter::ecs::SceneRulesSystem>();
  }

} // namespace space_shooter
