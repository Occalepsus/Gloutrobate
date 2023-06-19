#include <SFML/Graphics.hpp>
#include <iostream>
#include "mapGeneration.h"
#include "myMain.h"

#include "Engine/Engine.h"
#include "Player.h"
#include "PlayerContact.h"

int myMain() {
    // Setup game engine
    auto game = std::make_unique<gloutrobate::Engine>("Gloutobate", 1920, 1080, 60.0f, 60);

    // Get and setup Map
    int sel{ 0 };

    Map map{};
    std::vector<std::shared_ptr<Platform>> platformPtrs{};
    for (auto& element : map.generation(sel)) {
        platformPtrs.emplace_back(std::make_shared<Platform>(element));
        game->addGameObject(platformPtrs.back(), false);
    }
    std::vector<std::shared_ptr<Cake>> cakePtrs{};
    for (auto& element : map.generationCakes(sel)) {
        cakePtrs.emplace_back(std::make_shared<Cake>(element));
        game->addGameObject(cakePtrs.back(), false);
    }

    // Create players
    auto startingPos{ map.getStartingPosition(sel) };
    if (startingPos.size() != 2) {
        exit(1);
    }

    // Player 1
    sf::Texture textureP1{};
    if (!textureP1.loadFromFile("./resources/Player.png")) {
        exit(1);
    }
    auto player1 = std::make_shared<Player>(startingPos[0], sf::Vector2f(1.0f, 1.5f), textureP1);
    player1->setKeys(sf::Keyboard::Z, sf::Keyboard::Q, sf::Keyboard::S, sf::Keyboard::D);
    game->addGameObject(player1, true);

    // Player 2
    sf::Texture textureP2{};
    if (!textureP2.loadFromFile("./resources/Player2.png")) {
        exit(1);
    }
    auto player2 = std::make_shared<Player>(startingPos[1], sf::Vector2f(1.0f, 1.5f), textureP2);
    player2->setKeys(sf::Keyboard::Up, sf::Keyboard::Left, sf::Keyboard::Down, sf::Keyboard::Right);
    game->addGameObject(player2, true);

    PlayerContact playerContact{};
    playerContact.setPlayer1(player1);
    playerContact.setPlayer2(player2);
    playerContact.setPlatforms(platformPtrs);
    playerContact.setCakes(cakePtrs);

    game->setContactListener(&playerContact);

    // Setup for the frame counter
    uint32_t i{ 0 };
    sf::Font font{};
    if (!font.loadFromFile("./resources/ARIAL.TTF")) {
		exit(1);
	}
    //Display of the scores
    sf::Text score1{}; //score of player blue
    score1.setFont(font);
    score1.setPosition(20, 10);
    score1.setCharacterSize(30);
    score1.setFillColor(sf::Color::Blue);
    score1.setString("test1");
    //score1.setString(getScore);

    sf::Text score2{}; //score of player red
    score2.setFont(font);
    score2.setPosition(1800, 10);
    score2.setCharacterSize(30);
    score2.setFillColor(sf::Color::Red);
    score2.setString("test2");
    //score2.setString(getScore);

    // Setup for the text
    sf::Text text{};
    text.setFont(font);
    text.setPosition(100, 100);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Blue);

    std::string str{ "Hello world " };

    // Starts the game and setup for the update function which is passed as a lambda, need to capture the variables needed in update
    game->start([&game, &str, &i, &text,&score1, &score2]() {
        // This is called between every frame
        std::string temp{ str };
        temp.append(std::to_string(i));
        text.setString(temp);
        // Function used to draw something on the frame, cleared after every frame
        game->drawOnFrame(&text);
        game->drawOnFrame(&score1);
        game->drawOnFrame(&score2);
        i++;
    });

    // This is the order of the code called between each frame:
    // 1. The update function passed to the engine is called
    // 2. The physics is updated
    // 3. Catching each event
    // 4. Drawing on the frame

    return 0;
}