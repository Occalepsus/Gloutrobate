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
    int sel{ 1 };

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

    // Setup for the scores
    sf::Font font{};
    if (!font.loadFromFile("./resources/ARIAL.TTF")) {
		exit(1);
	}
    //Display of the scores
    //score of the blue player
    sf::Text score1{};
    score1.setFont(font);
    score1.setPosition(20, 10);
    score1.setCharacterSize(30);
    score1.setFillColor(sf::Color::Blue);
    std::string base1{ "Score player 1: " };

    //score of the red player
    sf::Text score2{};
    score2.setFont(font);
    score2.setPosition(1650, 10);
    score2.setCharacterSize(30);
    score2.setFillColor(sf::Color::Red);   
    std::string base2{ "Score player 2: " };

    // Starts the game and setup for the update function which is passed as a lambda, need to capture the variables needed in update
    game->start([&game, &base1, &base2, &score1, &score2, &player1, &player2, &cakePtrs]() {
        uint8 cakeCount{ 0 };
        std::ranges::for_each(cakePtrs.begin(), cakePtrs.end(), [&cakeCount](auto const& c) {
            if (c->isEaten()) {
                cakeCount++;
            }
            });
        if (cakeCount == cakePtrs.size()) {
            return false;
        }

        // This is called between every frame
        std::string scoreTxt1{ base1 };
        scoreTxt1.append(std::to_string(player1->getScore()));
        score1.setString(scoreTxt1);

        std::string scoreTxt2{ base2 };
        scoreTxt2.append(std::to_string(player2->getScore()));
        score2.setString(scoreTxt2);

        // Function used to draw something on the frame, cleared after every frame
        game->drawOnFrame(&score1);
        game->drawOnFrame(&score2);

        return true;
    });

    // This is the order of the code called between each frame:
    // 1. The update function passed to the engine is called
    // 2. The physics is updated
    // 3. Catching each event
    // 4. Drawing on the frame

    game.reset();

    // Create the victory window
    sf::RenderWindow victoryWindow(sf::VideoMode(800, 300), "Victory Window");
    sf::Text victory_text{};
    if (player1->getScore() == player2->getScore()) {
        victory_text.setString("Tie...");
        victory_text.setFillColor(sf::Color::Yellow);
    }
    else if (player1->getScore() > player2->getScore()) {
		victory_text.setString("Player 1 wins !");
        victory_text.setFillColor(sf::Color::Blue);
	}
	else {
		victory_text.setString("Player 2 wins !");
        victory_text.setFillColor(sf::Color::Red);
	}
    victory_text.setFont(font);
    auto bounds = sf::Vector2f{ victory_text.getGlobalBounds().width, victory_text.getGlobalBounds().height };
    victory_text.setPosition(sf::Vector2f{ static_cast<sf::Vector2f>(victoryWindow.getSize()) / 2.0f - bounds });
    victory_text.setCharacterSize(50);

    while (victoryWindow.isOpen()) {
        sf::Event event;
        while (victoryWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                victoryWindow.close();
            }
        }

        victoryWindow.clear();
        victoryWindow.draw(victory_text);
        victoryWindow.display();
    }

    return 0;
}