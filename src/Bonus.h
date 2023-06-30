#pragma once

#include "Item.h"
class Bonus : public Item {
public:
	enum class BonusType {
		speedBonus,
		jumpBonus
	};
	explicit Bonus(sf::Vector2f pos, BonusType bonusType) : Item(pos, sf::Vector2f(0.2, 0.2), getItemTexture()), _bonusType{ bonusType } {};
	BonusType getBonusType() const { return _bonusType; };
private:
	BonusType _bonusType;
};
