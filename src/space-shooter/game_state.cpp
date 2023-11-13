#include <space-shooter/game_state.hpp>

#include <space-shooter/utils.hpp>

namespace space_shooter {

std::unique_ptr<GameState> initGameState(const GameConfig &game_config) {

  auto config = Config{game_config.assets_path / "textures",
                       game_config.assets_path / "audio",
                       game_config.assets_path / "fonts"};

  return std::unique_ptr<GameState>(new GameState{
      //
      .config = config,
      .width = game_config.window_width,
      .height = game_config.window_height,
      .frame_rate_type = game_config.frame_rate,
      .rendering_window = initRenderingWindow(
          game_config.title, game_config.window_width,
          game_config.window_height, game_config.frame_rate),
      // First scene here is level, so first function to do is level.cpp : init_level()
      .switch_to_scene = GameState::Scene::Level,
      .running = true,
      .keep_entities = false,
      .keep_systems = false //
  });
}


} // namespace space_shooter
