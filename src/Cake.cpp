#include "Cake.h"

sf::Texture Cake::getCakeTexture() const {
	sf::Texture texture_cake;
	if (!texture_cake.loadFromFile("./resources/gateau.png")) {
		exit(1);
	}
	return texture_cake;
}

void Cake::start() {
	getBody()->GetFixtureList()->SetSensor(true);
}
void Cake::update() {
	if (_eaten) {
		move(1000, 0);
	}
}