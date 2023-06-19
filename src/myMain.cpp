#include <SFML/Graphics.hpp>
#include <iostream>
#include "mapGeneration.h"
#include "myMain.h"

#include "Engine/Engine.h"
#include "Player.h"

int myMain() {
    // Setup game engine
    auto game = std::make_unique<gloutrobate::Engine>("Gloutobate", 1920, 1080, 60.0f, 60);

    
    Map map{};
    list_platforms platforms{ map.generation(1) };

    for (auto& element : platforms) {
        game->addGameObject(&element , false);
    }

    // Create players
    // Player 1
    sf::Texture textureP1{};
    if (!textureP1.loadFromFile("./resources/Player.png")) {
        exit(1);
    }
    Player player1{ sf::Vector2f(2, 8), sf::Vector2f(1.0f, 1.5f), textureP1 };
    player1.setKeys(sf::Keyboard::Z, sf::Keyboard::Q, sf::Keyboard::S, sf::Keyboard::D);
    game->addGameObject(&player1, true);

    // Player 2
    sf::Texture textureP2{};
    if (!textureP2.loadFromFile("./resources/Player2.png")) {
        exit(1);
    }
    Player player2{ sf::Vector2f(2, 8), sf::Vector2f(1.0f, 1.5f), textureP2 };
    player2.setKeys(sf::Keyboard::Up, sf::Keyboard::Left, sf::Keyboard::Down, sf::Keyboard::Right);
    game->addGameObject(&player2, true);

    // Setup for the frame counter
    uint32_t i{ 0 };
    sf::Font font{};
    if (!font.loadFromFile("./resources/ARIAL.TTF")) {
		exit(1);
	}

    // Setup for the text
    sf::Text text{};
    text.setFont(font);
    text.setPosition(100, 100);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Blue);

    std::string str{ "Hello world " };

    // Starts the game and setup for the update function which is passed as a lambda, need to capture the variables needed in update
    game->start([&game, &str, &i, &text]() {
        // This is called between every frame
        std::string temp{ str };
        temp.append(std::to_string(i));
        text.setString(temp);
        // Function used to draw something on the frame, cleared after every frame
        game->drawOnFrame(&text);
        i++;
    });

    // This is the order of the code called between each frame:
    // 1. The update function passed to the engine is called
    // 2. The physics is updated
    // 3. Catching each event
    // 4. Drawing on the frame

    return 0;
}