#pragma once

#include "GameObject.h"

using namespace gloutrobate;

GameObject::GameObject(sf::Texture const& texture) : GameObject(sf::Vector2f{ 0.0f, 0.0f }, sf::Vector2f{ (float)texture.getSize().x, (float)texture.getSize().y }, texture) {};

GameObject::GameObject(sf::Vector2f const& pos, sf::Vector2f const& size, sf::Texture const& texture) : pos{ pos }, size{ size }, texture{ texture } {}

sf::Vector2f gloutrobate::GameObject::getPosition() const {
	return pos;
}
void GameObject::setPosition(sf::Vector2f p) {
	pos = p;
}
void gloutrobate::GameObject::setPosition(float x, float y) {
	pos = sf::Vector2f{ x, y };
}

sf::Vector2f gloutrobate::GameObject::getSize() const {
	return size;
}
void GameObject::setSize(sf::Vector2f s) {
	size = s;
}

sf::Texture const& GameObject::getTexture() const {
	return texture;
}

b2Body* gloutrobate::GameObject::getBody() const {
	return body;
}
void gloutrobate::GameObject::setBody(b2Body* b) {
	body = b;
}
