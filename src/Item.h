#pragma once

#include "Engine/GameObject.h"
class Item : public gloutrobate::GameObject {
private:

	bool _eaten{ false };

	using GameObject::GameObject;
	
protected:

	sf::Texture getItemTexture() const;
public:
	void eat();
	bool isEaten() const { return _eaten; }

	virtual void start();

	void onCollisionEnter(GameObject* other, b2Contact* contact) override;
};
