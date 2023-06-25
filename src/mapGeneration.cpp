#include "mapGeneration.h"
#include "Engine/Engine.h"
#include "Platform.h"
#include "Cake.h"
#include <random>
#include <cmath>
#include <vector>
#include <array>

using namespace gloutrobate;

//This function is used to generate the platforms of the map selected
std::vector<sf::Vector2f> Map::getPlatformPositions() const {
    std::array<std::vector<sf::Vector2f>, 2> maps {
        std::vector<sf::Vector2f> {
            sf::Vector2f(2.5f, 1.f),
            sf::Vector2f(14.5f, 1.f),
            sf::Vector2f(29.5f, 1.f),
            sf::Vector2f(7.5f, 3.f),
            sf::Vector2f(25.5f, 3.f),
            sf::Vector2f(10.5f, 5.f),
            sf::Vector2f(20.5f, 5.f),
            sf::Vector2f(15.5f, 8.f),
            sf::Vector2f(3.5f, 10.f),
            sf::Vector2f(29.5f, 10.f),
            sf::Vector2f(11.5f, 11.f),
            sf::Vector2f(20.5f, 11.f),
            sf::Vector2f(6.5f, 13.f),
            sf::Vector2f(25.5f, 14.f),
            sf::Vector2f(1.5f, 15.f),
            sf::Vector2f(15.5f, 15.f),
            sf::Vector2f(30.5f, 15.f)
        }, {
            sf::Vector2f(1.5f, 1.f),
            sf::Vector2f(9.5f, 1.f),
            sf::Vector2f(24.5f, 1.f),
            sf::Vector2f(27.5f, 1.f),
            sf::Vector2f(4.5f, 3.f),
            sf::Vector2f(13.5f, 4.f),
            sf::Vector2f(20.5f, 5.f),
            sf::Vector2f(30.5f, 5.f),
            sf::Vector2f(7.5f, 7.f),
            sf::Vector2f(2.5f, 8.f),
            sf::Vector2f(15.5f, 8.f),
            sf::Vector2f(28.5f, 9.f),
            sf::Vector2f(11.5f, 11.f),
            sf::Vector2f(6.5f, 12.f),
            sf::Vector2f(1.5f, 13.f),
            sf::Vector2f(30.5f, 13.f),
            sf::Vector2f(13.5f, 15.f),
            sf::Vector2f(19.5f, 15.f),
            sf::Vector2f(25.5f, 15.f),
            sf::Vector2f(3.5f, 17.f)
        }
    };
    return maps[_seed];
}

//This function is used to generate the cakes of the map selected
std::vector<sf::Vector2f> Map::getCakePositions() const {
    std::array<std::vector<sf::Vector2f>, 2> maps{
        std::vector<sf::Vector2f> {
            sf::Vector2f(2.5f, 2.f),
            sf::Vector2f(1.5f, 16.f),
            sf::Vector2f(7.f, 7.f),
            sf::Vector2f(9.5f, 10.f),
            sf::Vector2f(15.5f, 2.f),
            sf::Vector2f(19.f, 17.f),
            sf::Vector2f(22.5f, 10.f),
            sf::Vector2f(27.f, 7.f),
            sf::Vector2f(30.f, 16.f),
            sf::Vector2f(30.f, 2.f),
            }, {
            sf::Vector2f(1.f, 15.f),
            sf::Vector2f(2.5f, 9.f),
            sf::Vector2f(8.5f, 8.f),
            sf::Vector2f(12.5f, 5.f),
            sf::Vector2f(13.5f, 17.f),
            sf::Vector2f(16.5f, 16.5f),
            sf::Vector2f(6.f, 17.f),
            sf::Vector2f(25.5f, 8.f),
            sf::Vector2f(22.5f, 3.f),
            sf::Vector2f(18.5f, 10.f),
        }
    };
    return maps[_seed];
}

//This function is used to define the starting position of the players, depending on the map chosen
std::vector<sf::Vector2f> Map::getStartingPositions() const {
    std::vector<sf::Vector2f> vecteur;
    if (_seed == 1) {
        vecteur = { sf::Vector2f(0.5, 3), sf::Vector2f(2.5, 3) };
    }
    if (_seed == 0) {
        vecteur = { sf::Vector2f(15, 10), sf::Vector2f(16, 10)};
    }
    return vecteur;
}

  