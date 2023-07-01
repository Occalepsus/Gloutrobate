#include "Item.h"

void Item::onCollisionEnter(GameObject* other, b2Contact* contact) {
	if (other->getTag() == "Player") {
		eat();
	}
}

void Item::eat() {
	_eaten = true;
	setActive(false);
}