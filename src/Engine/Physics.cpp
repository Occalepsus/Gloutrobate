#include "Physics.h"

void gloutrobate::Physics::update(std::vector<GameObject*> const& gameObjects) {
	_world.Step(_timeStep, _velocityIterations, _positionIterations);

	for (auto const& gameObject : gameObjects) {
		gameObject->updatePositionFromPhysics();
	}
}

void gloutrobate::Physics::createDynamicBody(GameObject* gameObject, float mass) {
	b2BodyDef bodyDef{};
	bodyDef.position.Set(gameObject->getPosition().x, gameObject->getPosition().y);
	bodyDef.type = b2_dynamicBody;
	bodyDef.fixedRotation = true;
	b2Body* body = _world.CreateBody(&bodyDef);

	b2PolygonShape dynamicBox{};
	dynamicBox.SetAsBox(gameObject->getSize().x / 2 - dynamicBox.m_radius, (gameObject->getSize().y - dynamicBox.m_radius) / 2);

	b2FixtureDef fixtureDef{};
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = mass / gameObject->getSize().x * gameObject->getSize().y / 4;
	fixtureDef.friction = 0.3f;

	body->CreateFixture(&fixtureDef);

	gameObject->setBody(body);
}

void gloutrobate::Physics::createStaticBody(GameObject* gameObject) {
	b2BodyDef bodyDef{};
	bodyDef.position.Set(gameObject->getPosition().x, gameObject->getPosition().y);
	bodyDef.type = b2_staticBody;
	b2Body* body = _world.CreateBody(&bodyDef);

	b2PolygonShape staticBox{};
	staticBox.SetAsBox(gameObject->getSize().x / 2 - staticBox.m_radius, gameObject->getSize().y / 2 - staticBox.m_radius);

	body->CreateFixture(&staticBox, 0.0f);

	gameObject->setBody(body);
}
