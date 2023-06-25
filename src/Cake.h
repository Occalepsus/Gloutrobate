#pragma once

#include "Engine/GameObject.h"
class Cake : public gloutrobate::GameObject {
private :
	bool _eaten{ false };

	using GameObject::GameObject;
public:	
	void eat();
	bool isEaten() const { return _eaten; }

	void start() override;

	void onCollisionEnter(GameObject* other, b2Contact* contact) override;
};
