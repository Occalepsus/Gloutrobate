#include <SFML/Graphics.hpp>
#include <iostream>

#include "myMain.h"

#include "Graphics/Graphics.h"

void dealEvent(sf::Event e, sf::CircleShape& shape) {
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
    gloutobate::Graphics window{600, 800, "Gloutobate"};

    sf::CircleShape shape(150.F);
    shape.setFillColor(sf::Color::Green);

    do {
        window.addDrawable(&shape);
    } while (window.drawFrame([&shape](sf::Event e) { dealEvent(e, shape); }));

    return 0;
}