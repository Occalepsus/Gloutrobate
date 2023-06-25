#pragma once

#include <iostream>
#include <string>
#include <random>
#include "Engine/Engine.h"
#include "Platform.h"
#include "Cake.h"
#include <array>

class Map {
private:
	int _seed;

public : 
	Map() = delete;
	explicit Map(int seed) : _seed{ seed } {};

	std::vector<sf::Vector2f> getPlatformPositions() const;
	std::vector<sf::Vector2f> getCakePositions() const;
	std::vector<sf::Vector2f> getStartingPositions() const;
};