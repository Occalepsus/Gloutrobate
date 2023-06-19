#include "mapGeneration.h"
#include "Engine/Engine.h"
#include "Platform.h"
#include "Cake.h"
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

//This function is used to generate the platforms of the map selected
list_platforms Map::generation(int selection) const {
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
        Platform{ sf::Vector2f(30.5f, 15.f) }
        
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
        Platform{ sf::Vector2f(3.5f, 17.f) }
        
    } };
    //list_platforms map3;
    return maps[selection];
  
}

//This function is used to generate the cakes of the map selected
list_cakes Map::generationCakes(int selection) const {
    std::vector<list_cakes> maps{
        {Cake{ sf::Vector2f(2.5f, 2.f)},
        Cake{ sf::Vector2f(1.5f, 16.f)},
        Cake{ sf::Vector2f(7.f, 7.f)},
        Cake{ sf::Vector2f(9.5f, 10.f)},
        Cake{ sf::Vector2f(15.5f, 2.f)},
        Cake{ sf::Vector2f(19.f, 17.f)},
        Cake{ sf::Vector2f(22.5f, 10.f)},
        Cake{ sf::Vector2f(27.f, 7.f)},
        Cake{ sf::Vector2f(30.f, 16.f)},
        Cake{ sf::Vector2f(30.f, 2.f)},
        },
        {Cake{ sf::Vector2f(1.f, 15.f)},
        Cake{ sf::Vector2f(2.5f, 9.f)},
        Cake{ sf::Vector2f(8.5f, 8.f)},
        Cake{ sf::Vector2f(12.5f, 5.f)},
        Cake{ sf::Vector2f(13.5f, 17.f)},
        Cake{ sf::Vector2f(16.5f, 30.5f)},
        Cake{ sf::Vector2f(6.f, 31.f)},
        Cake{ sf::Vector2f(25.5f, 8.f)},
        Cake{ sf::Vector2f(22.5f, 3.f)},
        Cake{ sf::Vector2f(18.5f, 10.f)}}
    };
    return maps[selection];
}

//This function is used to define the starting position of the players, depending on the map chosen
std::vector<sf::Vector2f> Map::getStartingPosition(int selection) const {
    std::vector<sf::Vector2f> vecteur;
    if (selection == 1) {
        vecteur = { sf::Vector2f(0.5, 2), sf::Vector2f(2.5, 2) };
    }
    if (selection == 0) {
        vecteur = { sf::Vector2f(15, 10), sf::Vector2f(16, 10)};
    }
    return vecteur;
}

  