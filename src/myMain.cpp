#include <SFML/Graphics.hpp>
#include <iostream>

#include "myMain.h"

#include "Engine/Engine.h"

void dealEvent(sf::Event e, gloutrobate::GameObject const& shape) {
    if (e.type == sf::Event::KeyPressed)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            shape.getBody()->ApplyLinearImpulseToCenter(b2Vec2(0.0f, 0.005f), true);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            shape.getBody()->ApplyLinearImpulseToCenter(b2Vec2(0.0f, -0.005f), true);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            shape.getBody()->SetLinearVelocity(b2Vec2(-0.1f, shape.getBody()->GetLinearVelocity().y));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            shape.getBody()->SetLinearVelocity(b2Vec2(0.1f, shape.getBody()->GetLinearVelocity().y));
        }
    }
}

int myMain() {
    // Setup game engine
    auto game = std::make_unique<gloutrobate::Engine>("Gloutobate", 1920, 1080, 60);

    // Create a texture
    sf::Texture texture{};
    if (!texture.loadFromFile("./resources/gateau.png")) {
        exit(1);
    }

    // Create a game object
    gloutrobate::GameObject obj{ sf::Vector2f(0.2f, 0.8f), sf::Vector2f(0.1f, 0.1f), texture };
    game->addGameObject(&obj, true);
    gloutrobate::GameObject floor{sf::Vector2f(0.2f, 0.3f), sf::Vector2f(0.2f, 0.2f), texture};
    game->addGameObject(&floor, false);
    gloutrobate::GameObject floorRef{sf::Vector2f(0.4f, 0.5f), sf::Vector2f(0.2f, 0.2f), texture};
    game->addGameObject(&floorRef, false);

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

    // Setup for the update function which is passed as a lambda, need to capture the variables needed in update
    game->setUpdate([&game, &str, &i, &text]() {
        // This is called between every frame
        std::string temp{ str };
        temp.append(std::to_string(i));
        text.setString(temp);
        // Function used to draw something on the frame, cleared after every frame
        game->drawOnFrame(&text);
        i++;
    });
    // Actually starts the game, the lambda passed as parameter is called every frame for every event
    game->start([&obj](sf::Event e) { dealEvent(e, obj); });

    // For now, the game is never stopped, so this is never called

    // This is the order of the code called between each frame:
    // 1. The update function passed to the engine is called
    // 2. The physics is updated
    // 3. Catching each event
    // 4. Drawing on the frame

    return 0;
}