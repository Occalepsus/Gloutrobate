#pragma once

#include <iostream>
#include <string>
#include <random>
#include "Engine/Engine.h"
#include "Platform.h"
#include "Cake.h"
#include <array>

using list_platforms = std::vector<Platform>;
using list_cakes = std::vector<Cake>;

class Map {
public : 
	list_platforms generation(int selection);
	list_cakes generationCakes(int selection);
	std::vector<sf::Vector2f> getStartingPosition(int selection);
};