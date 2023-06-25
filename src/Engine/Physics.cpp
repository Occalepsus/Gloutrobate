#include "Physics.h"

void gloutrobate::Physics::update(std::span<GameObject*> const& gameObjects) {
	_world.Step(_timeStep, _velocityIterations, _positionIterations);

	for (auto& gameObjectPtr : gameObjects) {
		gameObjectPtr->updatePositionFromPhysics();
	}
}

void gloutrobate::Physics::createDynamicBody(GameObject* gameObjectPtr, float mass) {
	b2BodyDef bodyDef{};
	bodyDef.position.Set(gameObjectPtr->getPosition().x, gameObjectPtr->getPosition().y);
	bodyDef.type = b2_dynamicBody;
	bodyDef.fixedRotation = true;
	b2Body* body = _world.CreateBody(&bodyDef);

	b2PolygonShape dynamicBox{};
	dynamicBox.SetAsBox(gameObjectPtr->getSize().x / 2 - dynamicBox.m_radius, (gameObjectPtr->getSize().y - dynamicBox.m_radius) / 2);

	b2FixtureDef fixtureDef{};
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = mass / gameObjectPtr->getSize().x * gameObjectPtr->getSize().y / 4;
	fixtureDef.friction = 0.3f;

	body->CreateFixture(&fixtureDef);

	gameObjectPtr->setBody(body);
}

void gloutrobate::Physics::createStaticBody(GameObject* gameObjectPtr) {
	b2BodyDef bodyDef{};
	bodyDef.position.Set(gameObjectPtr->getPosition().x, gameObjectPtr->getPosition().y);
	bodyDef.type = b2_staticBody;
	b2Body* body = _world.CreateBody(&bodyDef);

	b2PolygonShape staticBox{};
	staticBox.SetAsBox(gameObjectPtr->getSize().x / 2 - staticBox.m_radius, gameObjectPtr->getSize().y / 2 - staticBox.m_radius);

	body->CreateFixture(&staticBox, 0.0f);

	gameObjectPtr->setBody(body);
}
