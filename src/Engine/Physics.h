#pragma once

#include "box2d/box2d.h"
#include <map>
#include <string>

#include "GameObject.h"

namespace gloutrobate {
	class Physics {
	private:
		b2World world{ b2Vec2(0.0f, -9.8f) };
		const float timeStep{ 1.0f / 60.0f };
		const int32 velocityIterations{ 6 };
		const int32 positionIterations{ 2 };
		const float skinWidth{ 0.1f };

	public:
		Physics() = default;
		explicit Physics(float fps) : timeStep{ 1.0f / fps } {};
		Physics(float fps, int velocityIterations, int positionIterations) : timeStep{ 1.0f / fps }, velocityIterations{ velocityIterations }, positionIterations{ positionIterations } {};

		void update(std::vector<GameObject*> const& gameObjects);

		void createDynamicBody(GameObject* gameObjectPtr, float mass);
		void createStaticBody(GameObject* gameObjectPtr);
	};
}