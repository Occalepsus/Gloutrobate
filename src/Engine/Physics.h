#pragma once

#include "box2d/box2d.h"
#include <map>
#include <string>
#include <span>

#include "GameObject.h"
#include "ContactListener.h"

namespace gloutrobate {
	class Physics {
	private:
		b2World _world{ b2Vec2(0.0f, -50) };
		const float _timeStep{ 1.0f / 60.0f };
		const int32 _velocityIterations{ 6 };
		const int32 _positionIterations{ 2 };
		const float _skinWidth{ 0.1f };

		const ContactListener _contactListener{};
		void setupContactListener() { _world.SetContactListener((b2ContactListener*)(&_contactListener)); };

	public:
		Physics() { setupContactListener(); };
		explicit Physics(float fps) : _timeStep{ 1.0f / fps } { setupContactListener(); };
		Physics(float fps, int velocityIterations, int positionIterations) :
			_timeStep{ 1.0f / fps }, _velocityIterations{ velocityIterations }, _positionIterations{ positionIterations } 
		{ setupContactListener(); };

		void update(std::span<GameObject*> const& gameObjects);

		void createDynamicBody(GameObject* gameObjectPtr, float mass);
		void createStaticBody(GameObject* gameObjectPtr);
	};
}