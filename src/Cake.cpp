#include "Cake.h"

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