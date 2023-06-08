#include <SFML/Graphics.hpp>
#include <iostream>

#include "myMain.h"

#include "Engine/Graphics.h"

void dealEvent(sf::Event e, gloutobate::GameObject& shape) {
    if (e.type == sf::Event::KeyPressed)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            shape.move(sf::Vector2(-5.0f, 0.0f));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            shape.move(sf::Vector2(5.0f, 0.0f));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            shape.move(sf::Vector2(0.0f, -5.0f));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            shape.move(sf::Vector2(0.0f, 5.0f));
        }
    }
}

int myMain() {
    gloutobate::Graphics window{1920, 1080, "Gloutobate"};

    sf::Texture texture{};
    if (!texture.loadFromFile("./resources/gateau.png")) {
        exit(1);
    }
    
    gloutobate::GameObject obj{ sf::Vector2f(0.0f, 0.0f), sf::Vector2f(100, 100), texture };
    window.addGameObject(&obj);

    uint32_t i{ 0 };
    sf::Font font{};
    if (!font.loadFromFile("./resources/ARIAL.TTF")) {
		exit(1);
	}

    // Text example
    sf::Text text{};
    text.setFont(font);
    text.setPosition(100, 100);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Blue);

    std::string str{ "Hello world " };
    do {
        // Text example between 2 frames
        std::string temp{ str };
        temp.append(std::to_string(i));
        text.setString(temp);
        window.addDrawableForOneFrame(&text);
        i++;
    } while (window.drawFrame([&obj](sf::Event e) { dealEvent(e, obj); }));

    return 0;
}