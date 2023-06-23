#include "Cake.h"

// TODO: Change that
sf::Texture Cake::getCakeTexture() const {
	sf::Texture texture_cake;
	if (!texture_cake.loadFromFile("./resources/gateau.png")) {
		exit(1);
	}
	return texture_cake;
}

void Cake::eat() {
	_eaten = true;
	setActive(false);
}

void Cake::start() {
	getBody()->GetFixtureList()->SetSensor(true);
}

void Cake::onCollisionEnter(GameObject* other, b2Contact* contact) {
	eat();
}