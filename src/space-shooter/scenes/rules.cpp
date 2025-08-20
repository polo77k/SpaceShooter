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
    std::string texte = "Regles du jeu :\n"
                        "Vous devez detruire tous les vaisseaux\n"
                        "ennemis, ainsi que le vaisseau mere pour\n"
                        "gagner.\n\n"
                        "Attention a votre barre de vie situee en haut\n"
                        "de l'ecran ! Ainsi qu'au chrono !!\n\n"
                        "Touches :\n"
                        "Fleches directionnelles pour se deplacer\n"
                        "dans toutes les directions.\n"
                        "Espace pour tirer.\n\n\n"
                        "Echap pour retourner au Menu.";
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
