#include "ContactListener.h"

#include "GameObject.h"

void gloutrobate::ContactListener::BeginContact(b2Contact* contact) {
	GameObject* gameObjectA = std::bit_cast<GameObject*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
	GameObject* gameObjectB = std::bit_cast<GameObject*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);

	if (gameObjectA != nullptr) {
		gameObjectA->onCollisionEnter(gameObjectB, contact);
	}
	if (gameObjectB != nullptr) {
		gameObjectB->onCollisionEnter(gameObjectA, contact);
	}
}

void gloutrobate::ContactListener::EndContact(b2Contact* contact) {
	GameObject* gameObjectA = std::bit_cast<GameObject*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
	GameObject* gameObjectB = std::bit_cast<GameObject*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);

	if (gameObjectA != nullptr) {
		gameObjectA->onCollisionExit(gameObjectB, contact);
	}
	if (gameObjectB != nullptr) {
		gameObjectB->onCollisionExit(gameObjectA, contact);
	}
}