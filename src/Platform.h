#pragma once

#include "Engine/GameObject.h"

class Platform : public gloutrobate::GameObject {
private:
	sf::Texture getPlatformTexture();

	using GameObject::GameObject;

public:
	explicit Platform(sf::Vector2f pos) : GameObject(pos, sf::Vector2f(3, 1), getPlatformTexture()) {};
};