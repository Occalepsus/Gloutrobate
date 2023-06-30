#include "Item.h"

sf::Texture Item::getItemTexture() const {
	sf::Texture texture_item;
	if (!texture_item.loadFromFile("./resources/gateau.png")) {
		exit(1);
	}
	return texture_item;
}

void Item::onCollisionEnter(GameObject* other, b2Contact* contact) {
	if (other->getTag() == "Player") {
		eat();
	}
}

void Item::eat() {
	_eaten = true;
	setActive(false);
}