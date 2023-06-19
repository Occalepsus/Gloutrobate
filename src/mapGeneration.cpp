#include "mapGeneration.h"
#include "Engine/Engine.h"
#include "Platform.h"
#include <random>
#include <cmath>
#include <vector>

using namespace gloutrobate;

/* GameObject Map::creationPlatform() {
    sf::Texture texture_platform{};
    if (!texture_platform.loadFromFile("./resources/platform.png")) {
        exit(1);
    }
    GameObject obj{ sf::Vector2f(float(std::rand()), float(std::rand())), sf::Vector2f(4,4), texture_platform};
    
    return obj;
}
*/

list_platforms Map::generation(int selection) {
    std::vector<list_platforms> maps{
    {
        Platform{ sf::Vector2f(2.5f, 1.f) },
        Platform{ sf::Vector2f(14.5f, 1.f)},
        Platform{ sf::Vector2f(29.5f, 1.f) },
        Platform{ sf::Vector2f(7.5f, 3.f) },
        Platform{ sf::Vector2f(25.5f, 3.f) },
        Platform{ sf::Vector2f(10.5f, 5.f) },
        Platform{ sf::Vector2f(20.5f, 5.f) },
        Platform{ sf::Vector2f(15.5f, 8.f) },
        Platform{ sf::Vector2f(3.5f, 10.f) },
        Platform{ sf::Vector2f(29.5f, 10.f) },
        Platform{ sf::Vector2f(11.5f, 11.f) },
        Platform{ sf::Vector2f(20.5f, 11.f) },
        Platform{ sf::Vector2f(6.5f, 13.f) },
        Platform{ sf::Vector2f(25.5f, 14.f) },
        Platform{ sf::Vector2f(1.5f, 15.f) },
        Platform{ sf::Vector2f(15.5f, 15.f) },
        Platform{ sf::Vector2f(30.5f, 15.f) },
    }, 
{
        Platform{ sf::Vector2f(1.5f, 1.f) },
        Platform{ sf::Vector2f(9.5f, 1.f) },
        Platform{ sf::Vector2f(24.5f, 1.f) },
        Platform{ sf::Vector2f(27.5f, 1.f) },
        Platform{ sf::Vector2f(4.5f, 3.f) },
        Platform{ sf::Vector2f(13.5f, 4.f) },
        Platform{ sf::Vector2f(20.5f, 5.f) },
        Platform{ sf::Vector2f(30.5f, 5.f) },
        Platform{ sf::Vector2f(7.5f, 7.f) },
        Platform{ sf::Vector2f(2.5f, 8.f) },
        Platform{ sf::Vector2f(15.5f, 8.f) },
        Platform{ sf::Vector2f(28.5f, 9.f) },
        Platform{ sf::Vector2f(11.5f, 11.f) },
        Platform{ sf::Vector2f(6.5f, 12.f) },
        Platform{ sf::Vector2f(1.5f, 13.f) },
        Platform{ sf::Vector2f(30.5f, 13.f) },
        Platform{ sf::Vector2f(13.5f, 15.f) },
        Platform{ sf::Vector2f(19.5f, 15.f) },
        Platform{ sf::Vector2f(25.5f, 15.f) },
        Platform{ sf::Vector2f(3.5f, 17.f) },
    } };
    //list_platforms map3;
    return maps[selection];
  
}