#pragma once

#include <array>
#include <SFML/Graphics.hpp>

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