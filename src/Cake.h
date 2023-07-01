#pragma once

#include "Item.h"
class Cake : public Item {
private :
	void start() override;
public:
	explicit Cake(sf::Vector2f pos, sf::Texture const& text) : Item(pos, sf::Vector2f(0.5,0.5), text) {};
};
