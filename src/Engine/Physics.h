#pragma once

#include "box2d/box2d.h"
#include <map>
#include <string>

#include "GameObject.h"

namespace gloutobate {
	class Physics {
	private:
		b2World world{ b2Vec2(0.0f, 9800.0f) };
		std::map<GameObject*, b2Body*> bodies{};
		const float timeStep{ 1.0f / 60.0f };
		const int32 velocityIterations{ 6 };
		const int32 positionIterations{ 2 };

	public:
		Physics() = default;
		explicit Physics(float fps) : timeStep{ 1.0f / fps } {};
		Physics(float fps, int velocityIterations, int positionIterations) : timeStep{ 1.0f / fps }, velocityIterations{ velocityIterations }, positionIterations{ positionIterations } {};

		void update();

		void createDynamicBody(GameObject*, float);
		void createStaticBody(GameObject*);
	};
}