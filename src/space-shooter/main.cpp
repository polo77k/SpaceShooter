// PROJECT HEADER HERE
#include <space-shooter/ecs/ecs.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/version.hpp>

// EXTERNAL HEADERS HERE
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

// SYSTEM HEADER HERE
#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <optional>
#include <string>

int main() {
  const auto game_config = space_shooter::GameConfig{
      .title = "Space Shooter",
      .window_width = 800,
      .window_height = 600,
      .assets_path = space_shooter::SPS_PATH_TO_ASSETS,
      .frame_rate = space_shooter::FrameRate::VERTICAL_SYNC //
  };

  auto manager = space_shooter::ecs::Manager(game_config);

  // Vaisseau
  std::string texte = "C:/Users/polo7/Documents/ESIEE/E4/Cours E4/Programation C++/Projet/squeleton/squeleton/assets/textures/spacecraft.png";
  sf::Vector2f initialPosition(100.0f, 100.0f);
  sf::Vector2f initialVelocite(0.0f, 0.0f);
  std::filesystem::path imagePath("textures/spacecraft.png");
  
  auto playerShip = space_shooter::ecs::PlayerShipEntity(initialPosition, imagePath, initialVelocite);
  manager.registerEntity<space_shooter::ecs::PlayerShipEntity>(std::move(playerShip));

  // RenderSystem
  auto renderingSystem = space_shooter::ecs::RenderingSystem();
  manager.registerSystem<space_shooter::ecs::RenderingSystem>(std::move(renderingSystem));


  // window
  auto *window = manager.gameState().rendering_window.get();
  auto clock = sf::Clock{};

  
  manager.enableAllSystems();

  while (window->isOpen() && manager.gameState().running) {
    auto event = sf::Event{};
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window->close();
    }

    window->clear();

    // call update on all registered systems
    manager.update(clock.restart());

    window->display();
  }

  return 0;
}


/*
int main()
{
    // Create a window with the title "Hello World"
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello World");

    // Create a green circle
    sf::CircleShape greenCircle(50); // Radius of the circle

    // Set the fill color to green
    greenCircle.setFillColor(sf::Color::Green);

    // Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear();

        // Draw the green circle
        window.draw(greenCircle);

        // Display the frame
        window.display();
    }

    return 0;
}*/
