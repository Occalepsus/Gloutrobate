#include "mapGeneration.h"
#include "Engine/Engine.h"
#include <random>
#include <cmath>
#include <vector>



gloutrobate::GameObject Map::creationPlatform() {
    sf::Texture texture_platform{};
    if (!texture_platform.loadFromFile("./resources/platform.png")) {
        exit(1);
    }
    gloutrobate::GameObject obj{ sf::Vector2f(float(std::rand()), float(std::rand())), sf::Vector2f(4,4), texture_platform};
    
    return obj;
}

std::vector<gloutrobate::GameObject> Map::generation() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> distribution(7.0, 2.0); //Generate the number of platform on the board
    int nbr_platform = std::ceil(distribution(gen));
    std::vector<gloutrobate::GameObject> vector;
    for (int i = 0;i < nbr_platform;i++) {
        vector.push_back(creationPlatform());
    }
    return vector;
}