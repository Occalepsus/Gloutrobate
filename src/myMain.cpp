#include <SFML/Graphics.hpp>
#include <iostream>

#include "myMain.h"

int myMain() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::CircleShape shape(150.F);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            // TODO : add keyboard control function or class
            if (event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                    std::cout << "control:" << std::endl;
                    shape.move(sf::Vector2(-5.0f, 0.0f));
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    std::cout << "control:" << std::endl;
                    shape.move(sf::Vector2(5.0f, 0.0f));
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                    std::cout << "control:" << std::endl;
                    shape.move(sf::Vector2(0.0f, -5.0f));
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    std::cout << "control:" << std::endl;
                    shape.move(sf::Vector2(0.0f, 5.0f));
                }
                // TODO : maybe not necessary
                window.clear();
                window.draw(shape);
                window.display();
            }

        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}