#pragma once

#include "box2d/box2d.h"
#include <map>
#include <string>
#include <span>

#include "GameObject.h"

namespace gloutrobate {
	class Physics {
	private:
		b2World _world{ b2Vec2(0.0f, -50) };
		const float _timeStep{ 1.0f / 60.0f };
		const int32 _velocityIterations{ 6 };
		const int32 _positionIterations{ 2 };
		const float _skinWidth{ 0.1f };

	public:
		Physics() = default;
		explicit Physics(float fps) : _timeStep{ 1.0f / fps } {};
		Physics(float fps, int velocityIterations, int positionIterations) : _timeStep{ 1.0f / fps }, _velocityIterations{ velocityIterations }, _positionIterations{ positionIterations } {};

		void update(std::span<std::shared_ptr<GameObject>> const& gameObjects);

		void createDynamicBody(std::shared_ptr<GameObject> gameObjectPtr, float mass);
		void createStaticBody(std::shared_ptr<GameObject> gameObjectPtr);

		void setContactListener(b2ContactListener* contactListener);
	};
}